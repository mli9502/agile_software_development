#ifndef APPLICATION_RUNNER_H
#define APPLICATION_RUNNER_H

#include <common_includes.h>

class Application;

class ApplicationRunner {
private:
    shared_ptr<Application> m_itsApplication;

public:
    ApplicationRunner(shared_ptr<Application> app) : m_itsApplication(app) {}

    void run();
};

#endif
