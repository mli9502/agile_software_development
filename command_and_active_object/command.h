#ifndef COMMAND_H
#define COMMAND_H

#include <common_includes.h>

class Command {
 public:
  virtual ~Command() = default;
  virtual void execute() = 0;
};

#endif

