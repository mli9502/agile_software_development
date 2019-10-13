#ifndef DELAYED_TYPER_H
#define DELAYED_TYPER_H

#include <common_includes.h>

#include <active_object_engine.h>
#include <command.h>

class DelayedTyper : public Command,
                     public enable_shared_from_this<DelayedTyper> {
 private:
  long _itsDelay;
  char _itsChar;

 public:
  static ActiveObjectEngine _engine;
  static bool _stop;

  DelayedTyper(long delay, char c) : _itsDelay(delay), _itsChar(c) {}
  ~DelayedTyper() = default;

  void execute() override;
  void delayAndRepeat();
};

#endif
