#include <application_runner.h>

#include <application.h>

void ApplicationRunner::run() {
  m_itsApplication->init();
  while (!m_itsApplication->done()) {
    m_itsApplication->idle();
  }
  m_itsApplication->cleanup();
}



