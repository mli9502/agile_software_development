#ifndef FTOC_STRATEGY_H
#define FTOC_STRATEGY_H

#include <application.h>

class FtocStrategy : public Application {
 private:
  string m_testFileName;
  shared_ptr<ifstream> m_fd;
  bool m_isDone;

 protected:
  void init() override { m_fd = make_shared<ifstream>(m_testFileName); }

  void idle() override {
    if (!m_fd->is_open()) {
      m_isDone = true;
      return;
    }
    string line;
    if (!getline(*m_fd, line)) {
      m_isDone = true;
      return;
    }

    try {
      double fahr = stod(line);
      double celcius = 5.0 / 9.0 * (fahr - 32.0);
      cout << "F = " << fahr << ", C = " << celcius << endl;
    } catch (const invalid_argument& e) {
      cerr << e.what() << endl;
    } catch (const out_of_range& e) {
      cerr << e.what() << endl;
    }
  }

  void cleanup() override { cout << "ftoc exit..." << endl; }

  bool done() override { return m_isDone; }

 public:
  FtocStrategy(const string& testFileName)
      : m_testFileName(testFileName), m_isDone(false) {}
};

#endif
