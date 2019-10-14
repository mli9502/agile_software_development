#include <application_runner.h>
#include <ftoc_strategy.h>

int main(void) {
  auto ar = ApplicationRunner(make_shared<FtocStrategy>("./fahr.txt"));
  ar.run();
  return 0;
}



