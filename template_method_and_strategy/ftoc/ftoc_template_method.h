#ifndef FTOC_TEMPLATE_METHOD_H
#define FTOC_TEMPLATE_METHOD_H

#include <application.h>

class FtocTemplateMethod : public Application {
   private:
    string m_testFileName;
    shared_ptr<ifstream> m_fd;

   protected:
    void init() override { m_fd = make_shared<ifstream>(m_testFileName); }

    void idle() override {
        if (!m_fd->is_open()) {
            setDone();
            return;
        }
        string line;
        while (getline(*m_fd, line)) {
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
        setDone();
        return;
    }

    void cleanup() override { cout << "ftoc exit..." << endl; }

   public:
    FtocTemplateMethod(const string& testFileName)
        : m_testFileName(testFileName) {}
};

#endif
