#include <iostream>
#include <fstream>

using namespace std;
int main() {
    streambuf *psbuf, *backup;
    ofstream log;
    log.open("log.txt");
    backup = clog.rdbuf();
    psbuf = log.rdbuf();
    clog.rdbuf(psbuf);
    clog<< "Start"<<endl;
    cout << "Hello, World!" << std::endl;
    clog<< "Finish"<<endl;
    clog.rdbuf(backup);
    log.close();
    return 0;
}
