#include <active_object_engine.h>
#include <command.h>
#include <sleep_command.h>

#include <chrono>

#include <gmock/gmock.h>

using namespace testing;

class SleepCommandTestFixture : public Test {
 public:
  SleepCommandTestFixture() {}

  void SetUp() override { wakeupCommandExecuted = false; }

  static bool wakeupCommandExecuted;
};

class WakeupCommand : public Command {
 public:
  void execute() override {
    SleepCommandTestFixture::wakeupCommandExecuted = true;
  }
};

bool SleepCommandTestFixture::wakeupCommandExecuted = false;

TEST_F(SleepCommandTestFixture, TestSleep) {
  ActiveObjectEngine e;
  auto sp = make_shared<SleepCommand>(1000, e, make_shared<WakeupCommand>());
  e.addCommand(sp);
  long start = chrono::duration_cast<chrono::milliseconds>(
                   chrono::system_clock::now().time_since_epoch())
                   .count();
  e.run();
  long stop = chrono::duration_cast<chrono::milliseconds>(
                  chrono::system_clock::now().time_since_epoch())
                  .count();
  long sleepTime = stop - start;
  EXPECT_THAT(sleepTime, AllOf(Ge(1000), Le(1100)));
  EXPECT_TRUE(wakeupCommandExecuted);
}
