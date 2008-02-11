#ifndef _SERVER_TASK_
#define _SERVER_TASK_

#include "Server.h"

#include "ace/Task.h"
#include "ace/ARGV.h"

class Server_Task : public ACE_Task_Base
{
 public:

  Server_Task (const std::string& args)
    : args_ (args)
  { }
  ~Server_Task ()
    {
      this->force_shutdown ();
    }

  virtual int svc ()
  {
    bool initializer = false;
    {
      ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->mutex_, -1);
      if (server_.get() == 0) {
  ACE_ARGV my_args (args_.c_str());

  // Initialize Server ORB in new thread
  server_.reset (new Server (my_args.argc(), my_args.argv()));
  ACE_ASSERT (server_.get() != 0);
  initializer = true;
      }
    }

    if (initializer) {
      server_->run (false);
    }
    else {
      server_->run (true);
    }

    this->force_shutdown ();

    return 0;
  }

  bool ready ()
  {
    if (server_.get() != 0) {
      return server_->init_;
    }

    return false;
  }

  void force_shutdown ()
  {
    if (server_.get() != 0) {
      server_->shutdown ();
    }
  }

 private:
  std::string args_;
  std::auto_ptr<Server> server_;
  TAO_SYNCH_MUTEX mutex_;
};

#endif //_SERVER_TASK_
