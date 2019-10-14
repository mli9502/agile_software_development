#ifndef SLEEP_COMMAND_H
#define SLEEP_COMMAND_H

#include <common_includes.h>

#include <active_object_engine.h>
#include <command.h>

class SleepCommand : public Command,
                     public enable_shared_from_this<SleepCommand> {
 private:
  shared_ptr<Command> _wakeupCommand;
  // For ActiveObjectEngine, we have to use reference.
  // This is because make_shared<ActiveObjectEngine>(&_engine) will create
  // multiple shared_ptr without them sharing the same control block.
  // This will later cause problem when they are being destructed.
  ActiveObjectEngine& _engine;
  long _sleepTime;
  long _startTime;
  bool _started;

 public:
  SleepCommand(long milliseconds,
               ActiveObjectEngine& e,
               shared_ptr<Command> wakeupCommand)
      : _engine(e), _sleepTime(milliseconds), _startTime(0), _started(false) {
    _wakeupCommand = wakeupCommand;
  }
  ~SleepCommand() = default;

  void execute() override;
};

#endif



