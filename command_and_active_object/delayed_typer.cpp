#include <delayed_typer.h>
#include <sleep_command.h>

ActiveObjectEngine DelayedTyper::_engine = ActiveObjectEngine();
bool DelayedTyper::_stop = false;

void DelayedTyper::execute() {
    cout << _itsChar;
    if(!_stop) {
        delayAndRepeat();
    }
}

void DelayedTyper::delayAndRepeat() {
    // In here, a new SleepCommand object will be created. 
    _engine.addCommand(make_shared<SleepCommand>(_itsDelay, _engine, shared_from_this()));
}