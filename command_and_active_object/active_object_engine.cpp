#include <active_object_engine.h>

void ActiveObjectEngine::addCommand(shared_ptr<Command> c) {
    _itsCommands.emplace_back(c);
}

void ActiveObjectEngine::run() {
    while (!_itsCommands.empty()) {
        auto firstCommand = _itsCommands[0];
        _itsCommands.erase(_itsCommands.begin());
        firstCommand->execute();
    }
}
