//
// Created by justnik on 21.11.2020.
//

#ifndef O_RAN_IWRITER_H
#define O_RAN_IWRITER_H
#include <string>

class IWriter {
public:
    virtual void print(std::string& str) = 0;
};


#endif //O_RAN_IWRITER_H
