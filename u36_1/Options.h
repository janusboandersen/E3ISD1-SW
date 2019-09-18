//
// Created by Janus Bo Andersen on 18/9/19.
//

#ifndef U36_1_OPTIONS_H
#define U36_1_OPTIONS_H

#include <iostream>
#include <string>

class Options {
public:
    Options() {} //default constructor
    Options(int argc, char** argv) : argc(argc), argv(argv) {} //member initialization list syntax
    ~Options() {} //default destructur
    bool isPresent(char c); //check if option c is available

private:
    int argc = 0;
    char** argv;
};

#endif //U36_1_OPTIONS_H
