//
// Created by Janus Bo Andersen.
//

#ifndef U38_2_OPTIONSCHARS_H
#define U38_2_OPTIONSCHARS_H

#include "Options.h" //base class

#include <iostream>
#include <string>
#include <vector>

class OptionsChars : public Options {
public:
    OptionsChars() {}; // default derived class constructor
    OptionsChars(int argc, char** argv) : Options(argc, argv) { parseGivenOpts(); } //call base class ctor first

private: //Pure virtual, must be implemented in subclasses
    void parseGivenOpts() override; //parse the argv list for options given
};

#endif //U38_2_OPTIONSCHARS_H
