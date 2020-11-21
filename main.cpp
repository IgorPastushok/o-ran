#include <iostream>
#include <string>
#include "writer/ConsoleWriter.h"
#include "writer/HTTPWriter.h"
#include "reader/JSONReader.h"

using namespace std;

int main() {
    streambuf *psbuf, *backup;
    ofstream log;
    log.open("log.txt");
    backup = clog.rdbuf();
    psbuf = log.rdbuf();
    clog.rdbuf(psbuf);
    clog<< "Start"<<endl;
    ConsoleWriter c;
    string msg = "hello";
    c.write(msg);
    HTTPWriter h("127.0.0.1","8080");
    JSONReader r("warcraft-3-quotes.json");
    string res = r.getQuote();
    h.write(res);
    clog << res << endl;
    clog << "Finish"<<endl;
    clog.rdbuf(backup);
    log.close();
    return 0;
}
