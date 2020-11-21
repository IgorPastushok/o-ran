#include <iostream>
#include <fstream>
#include <string>
#include "ConsoleWriter.h"
#include "HTTPWriter.h"
#include "JSONReader.h"

using namespace std;

int main() {
    streambuf *psbuf, *backup;
    ofstream log;
    log.open("log.txt");
    backup = clog.rdbuf();
    psbuf = log.rdbuf();
    clog.rdbuf(psbuf);
    clog<< "Start"<<endl;
    /*ConsoleWriter c;
    string msg = "hello";
    c.write(msg);
    HTTPWriter h("127.0.0.1","8080");
    h.isReachable();*/
    JSONReader r("warcraft-3-quotes.json");
    string res = r.getQuote();
    clog << res << endl;
    clog << "Finish"<<endl;
    clog.rdbuf(backup);
    log.close();
    return 0;
}
