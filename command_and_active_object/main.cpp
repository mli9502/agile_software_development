#include <common_includes.h>

#include <delayed_typer.h>
#include <sleep_command.h>
#include <stop_command.h>

int main(void) {
  DelayedTyper::_engine.addCommand(make_shared<DelayedTyper>(100, '1'));
  DelayedTyper::_engine.addCommand(make_shared<DelayedTyper>(200, '2'));
  DelayedTyper::_engine.addCommand(make_shared<DelayedTyper>(300, '3'));
  DelayedTyper::_engine.addCommand(make_shared<DelayedTyper>(400, '4'));
  // This SleepCommand is needed to set DelayedTyper::_stop to true to terminate
  // all the DelayedTyper instances.
  DelayedTyper::_engine.addCommand(make_shared<SleepCommand>(
      5000, DelayedTyper::_engine, make_shared<StopCommand<DelayedTyper>>()));

  DelayedTyper::_engine.run();

  return 0;
}
