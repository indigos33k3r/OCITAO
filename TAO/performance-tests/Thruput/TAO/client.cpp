// $Id$

// ============================================================================
//
// = TAO tests
//    Throughput measurement using the TTCP benchmark adapted to work
//    using TAO
//
// = FILENAME
//   client.cpp
//
//   Main program for the client
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include "ttcpC.h"
#include "ttcp_decl.h"

#include "tao/debug.h"

#include "ace/ACE.h"
#include "ace/Read_Buffer.h"
#include "ace/Get_Opt.h"

ACE_RCSID(TAO, client, "$Id$")

int print_usage (void);

char * read_ior (char *filename);
char Usage[] =
     "Usage: client [-options] \n"
     "Common options:\n"
     "-i <ior> Object reference string that the server outputs when started\n"
     "-f ior_file\n"
     "-l ##    length of bufs read from or written to network (default 8192)\n"
     "-v       verbose: print more statistics\n"
     "-d ##    debug level\n"
     "-m X     format for rate: k,K = kilo{bit,byte}; m,M = mega; g,G = giga\n"
     "-L ##    Output file name to store results\n"
     "-S ##    Total Data Size to be sent\n"
     "-q <type> Send Sequence: Enumeration for various data types:\n"
     "          s = short, l = long,  d = double, c = char\n"
     "          o = octet, S = BinStruct \n";

CORBA::Long trans = 1;          // we are a client - used for debugging purposes
CORBA::Long buflen = 8 * 1024;  // length of buffer, default 8,192 bytes
CORBA::Char *buf;               // ptr to dynamic buffer
CORBA::Long nbuf;               // number of buffers to send in sinkmode
CORBA::Short port = TAO_DEFAULT_SERVER_PORT;    // TCP port number
const char* host = "localhost";              // ptr to name of host
CORBA::Long verbose = 0;        // 0=print basic info, 1=print cpu
                                // rate, proc resource usage.
CORBA::Char fmt = 'K';          // output
                                // format:k=kilobits,K=kilobytes, m = megabits,
                                // M = megabytes, g = gigabits, G = gigabytes
char* title = 0;        // title of file to gather statistics
char stats[128];                // gathering the statistics
unsigned long srcDataSize;      // Total amount of source data
unsigned long nbytes;           // bytes on net
unsigned long numCalls;         // # of I/O system calls
double cput, realt;             // user, real time (seconds)
unsigned long   dt;             // data type
char * ior = 0;

// declare variables for various message types
ttcp_sequence::ShortSeq         *sseq;
ttcp_sequence::LongSeq          *lseq;
ttcp_sequence::OctetSeq         *oseq;
ttcp_sequence::DoubleSeq        *dseq;
ttcp_sequence::CharSeq          *cseq;
ttcp_sequence::StructSeq        *Sseq;

int
main (int argc, char *argv[])
{

  int c;
  CORBA::ORB_ptr        orb_ptr;   // underlying ORB
                                            // server
  CORBA::Object_ptr     objref = CORBA::Object::_nil(); // object reference
  ttcp_sequence_ptr     ttcp_seq = 0;  // obj reference to TTCP object

  // parse the arguments
  ACE_Get_Opt get_opt (argc, argv, "d:vm:l:L:S:q:i:f:");
  TAO_debug_level = 0;
  while ((c = get_opt ()) != -1)
    {
      switch (c)
        {
        case 'i':
          ior = ACE_OS::strdup (get_opt.optarg);
          break;
        case 'L':
          title = ACE_OS::strdup (get_opt.optarg);
          break;
        case 'd':
          TAO_debug_level = ACE_OS::atoi (get_opt.optarg);
          if (TAO_debug_level > 10)
            TAO_debug_level = 10;
          break;
        case 'l':
          buflen = ACE_OS::atoi (get_opt.optarg);
          break;
        case 'v':
          verbose = 1;
          break;
        case 'm':
          fmt = *get_opt.optarg;
          break;
        case 'S':       /* total source data to send. */
          srcDataSize = ACE_OS::atoi (get_opt.optarg);
          break;
        case 'q':       /* Send sequence of desired data type */
          switch(*get_opt.optarg){
          case 's':
            dt = SEND_SHORT;
            break;
          case 'l':
            dt = SEND_LONG;
            break;
          case 'd':
            dt = SEND_DOUBLE;
            break;
          case 'c':
            dt = SEND_CHAR;
            break;
          case 'o':
            dt = SEND_OCTET;
            break;
          case 'S':
            dt = SEND_STRUCT;
            break;
          case 'C':
            dt = SEND_COMPOSITE;
            break;
          }
          break;
        case 'f':
          ior = read_ior (get_opt.optarg);
          break;
        default:
          return print_usage ();
        }
    }

  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      //
      // Transmitter
      //

      // get a handle to the ORB
      orb_ptr = CORBA::ORB_init (argc, argv, "internet", ACE_TRY_ENV);
      ACE_TRY_CHECK;

      ACE_DEBUG ((LM_DEBUG, "Read IOR string as: %s\n" , ior));

      // retrieve an object reference out of the stringified IOR
      objref = orb_ptr->string_to_object (ior, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (!CORBA::is_nil (objref))
        {
          // if it is a valid obj ref, narrow it to a ttcp_sequence
          // CORBA object
          ttcp_seq = ttcp_sequence::_narrow (objref, ACE_TRY_ENV);
          ACE_TRY_CHECK;

          if (!CORBA::is_nil (ttcp_seq))
            {
              // the number of iterations is based on the total data size and the
              // individual buffer size sent
              nbuf = srcDataSize/buflen;
              ACE_DEBUG ((LM_DEBUG, "data size = %d, buflen = %d, nbuf = %d\n",
                          srcDataSize, buflen, nbuf));

              //
              // Prepare the Message to be sent
              //


              // first allocate a buffer of the desired size and alignment
              errno = 0;
              if ((buf = (char *) ACE_OS::malloc (buflen)) == (char *) NULL)
                err ("malloc");

              // fill the buffer with the data type to be sent
              FillPattern (buf, buflen, dt);

              //
              // Start the timers on the client and server sides
              //

              prep_timer ();  // start our time
              // ask the server to start its timer
              ttcp_seq->start_timer (ACE_TRY_ENV);
              ACE_TRY_CHECK;

#if defined (ACE_HAS_QUANTIFY)
              /* start recording quantify data from here */
              quantify_clear_data ();
              quantify_start_recording_data ();
#endif /* ACE_HAS_QUANTIFY */
              // send the same buffer nbuf times
              while (nbuf--)
                {
                  switch (dt)
                    {
                    case SEND_SHORT:
                      ttcp_seq->sendShortSeq (*sseq, ACE_TRY_ENV);
                      ACE_TRY_CHECK;
                      nbytes += sseq->length () * sizeof (CORBA::Short);
                      break;
                    case SEND_LONG:
                      ttcp_seq->sendLongSeq (*lseq, ACE_TRY_ENV);
                      ACE_TRY_CHECK;
                      nbytes += lseq->length () * sizeof (CORBA::Long);
                      break;
                    case SEND_OCTET:
                      ttcp_seq->sendOctetSeq (*oseq, ACE_TRY_ENV);
                      ACE_TRY_CHECK;
                      nbytes += oseq->length () * sizeof (CORBA::Octet);
                      break;
                    case SEND_DOUBLE:
                      ttcp_seq->sendDoubleSeq (*dseq, ACE_TRY_ENV);
                      ACE_TRY_CHECK;
                      nbytes += dseq->length () * sizeof (CORBA::Double);
                      break;
                    case SEND_CHAR:
                      ttcp_seq->sendCharSeq (*cseq, ACE_TRY_ENV);
                      ACE_TRY_CHECK;
                      nbytes += cseq->length () * sizeof (CORBA::Char);
                      break;
                    case SEND_STRUCT:
                      ttcp_seq->sendStructSeq (*Sseq, ACE_TRY_ENV);
                      ACE_TRY_CHECK;
                      nbytes += Sseq->length () * sizeof (BinStruct);
                      break;
                  }
                  numCalls++; // nbytes and numCalls are used in the thruput
                  // measurement
                }
            }
#if defined (ACE_HAS_QUANTIFY)
          quantify_stop_recording_data();
#endif /* ACE_HAS_QUANTIFY */
          //
          // Stop the timer
          //
          // stop the timer on the server side
          ttcp_seq->stop_timer (ACE_TRY_ENV);
          ACE_TRY_CHECK;

          // stop our timer
          (void) read_timer (stats, sizeof (stats));

          // print results
          PrintStats();
        }

      CORBA::release (ttcp_seq);
      CORBA::release (objref);
      CORBA::release (orb_ptr);
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "client");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  return 0;
}

int print_usage (void)
{
  ACE_ERROR ((LM_ERROR, "Usage error\n"));
  ACE_ERROR ((LM_ERROR, "%s\n", Usage));
  return -1;
}

char*
read_ior (char *filename)
{
  ACE_HANDLE f_handle;
  // Open the file for reading.
  f_handle = ACE_OS::open (filename, O_RDONLY);

  if (f_handle == ACE_INVALID_HANDLE)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Unable to open %s for reading: %p\n",
                       filename?filename:"(null filename)"),
                      0);
  ACE_Read_Buffer ior_buffer (f_handle);
  char *data = ior_buffer.read ();

  if (data == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Unable to allocate memory to read ior: %p\n"),
                      0);

  char *ior = 0;
  ior = ACE_OS::strdup (data);
  ior_buffer.alloc ()->free (data);

  return ior;
}
