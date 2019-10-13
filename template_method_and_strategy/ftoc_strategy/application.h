#ifndef APPLICATION_H
#define APPLICATION_H

#include <common_includes.h>

class Application {
 public:
  virtual void init() = 0;
  virtual void idle() = 0;
  virtual void cleanup() = 0;
  virtual bool done() = 0;
};

#endif
