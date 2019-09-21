//
// Created by Janus Bo Andersen.
//

#ifndef U38_2_OPTIONSKEYWORDS_H
#define U38_2_OPTIONSKEYWORDS_H

#include "Options.h" //base class

#include <iostream>
#include <string>
#include <vector>

class OptionsKeywords : public Options {
public:
    OptionsKeywords() {}; // default derived class constructor
    OptionsKeywords(int argc, char** argv) : Options(argc, argv) { parseGivenOpts(); } //call base class ctor first

private: //Pure virtual, must be implemented in subclasses
    void parseGivenOpts() override; //parse the argv list for options given
};

#endif //U38_2_OPTIONSKEYWORDS_H
