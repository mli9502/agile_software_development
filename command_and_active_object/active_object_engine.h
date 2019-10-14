#ifndef ACTIVE_OBJECT_ENGINE_H
#define ACTIVE_OBJECT_ENGINE_H

#include <common_includes.h>

#include <command.h>

class ActiveObjectEngine {
 private:
  vector<shared_ptr<Command>> _itsCommands;

 public:
  void addCommand(shared_ptr<Command> c);
  void run();
};

#endif



