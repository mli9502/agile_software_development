#ifndef APPLICATION_H
#define APPLICATION_H

#include <common_includes.h>

class Application {
 private:
  bool m_isDone;

 protected:
  virtual void init() = 0;
  virtual void idle() = 0;
  virtual void cleanup() = 0;

  void setDone() { m_isDone = true; }

  bool done() { return m_isDone; }

 public:
  void run() {
    init();
    while (!done()) {
      idle();
    }
    cleanup();
  }
};

#endif
