// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:323


#include "RTPortableServerC.h"
#include "tao/CDR.h"
#include "tao/Typecode.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "RTPortableServerC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:64

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for RTPortableServer::POA.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
RTPortableServer::POA_ptr
TAO::Objref_Traits<RTPortableServer::POA>::tao_duplicate (
    RTPortableServer::POA_ptr p
  )
{
  return RTPortableServer::POA::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<RTPortableServer::POA>::tao_release (
    RTPortableServer::POA_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
RTPortableServer::POA_ptr
TAO::Objref_Traits<RTPortableServer::POA>::tao_nil (void)
{
  return RTPortableServer::POA::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<RTPortableServer::POA>::tao_marshal (
    RTPortableServer::POA_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*RTPortableServer__TAO_POA_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

RTPortableServer::POA::POA (void)
{}

RTPortableServer::POA::~POA (void)
{}

void 
RTPortableServer::POA::_tao_any_destructor (void *_tao_void_pointer)
{
  POA *_tao_tmp_pointer =
    ACE_static_cast (POA *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

RTPortableServer::POA_ptr
RTPortableServer::POA::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return POA::_nil ();
    }
  
  POA_ptr proxy =
    dynamic_cast<POA_ptr> (_tao_objref);
  
  return POA::_duplicate (proxy);
}

RTPortableServer::POA_ptr
RTPortableServer::POA::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return POA::_nil ();
    }
  
  POA_ptr proxy =
    dynamic_cast<POA_ptr> (_tao_objref);
  
  return POA::_duplicate (proxy);
}

RTPortableServer::POA_ptr
RTPortableServer::POA::_duplicate (POA_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
RTPortableServer::POA::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/PortableServer/POA:2.3"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/RTPortableServer/POA:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* RTPortableServer::POA::_interface_repository_id (void) const
{
  return "IDL:omg.org/RTPortableServer/POA:1.0";
}

CORBA::Boolean
RTPortableServer::POA::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1628

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        RTPortableServer::POA
      >;

  template class
    TAO_Objref_Var_T<
        RTPortableServer::POA
      >;
  
  template class
    TAO_Objref_Out_T<
        RTPortableServer::POA
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        RTPortableServer::POA \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        RTPortableServer::POA
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        RTPortableServer::POA
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

