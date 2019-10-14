#ifndef STOP_COMMAND_H
#define STOP_COMMAND_H

#include <common_includes.h>

#include <command.h>

template <typename T>
class StopCommand : public Command {
 public:
  void execute() override { T::_stop = true; }
};

#endif



