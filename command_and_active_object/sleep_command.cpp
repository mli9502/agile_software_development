#include <sleep_command.h>

#include <chrono>

void SleepCommand::execute() {
  long currentTime = chrono::duration_cast<chrono::milliseconds>(
                         chrono::system_clock::now().time_since_epoch())
                         .count();
  if (!_started) {
    // cout << endl << "start a new SleepCommand at time: " << currentTime <<
    // endl;
    _started = true;
    _startTime = currentTime;
    // Note that in here, we have to use shared_from_this() instead of
    // shared_ptr<T>(this).
    // This is because shared_ptr<T>(this) will create a NEW control block.
    // And, this will later cause problem when one of these shared_ptr is
    // destructed.
    _engine.addCommand(shared_from_this());
  } else if (currentTime - _startTime < _sleepTime) {
    _engine.addCommand(shared_from_this());
  } else {
    _engine.addCommand(_wakeupCommand);
  }
}


