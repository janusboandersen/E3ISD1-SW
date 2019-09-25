//
// Created by Janus Bo Andersen.
//

#ifndef U38_2_OPTIONS_H
#define U38_2_OPTIONS_H

#include <iostream>
#include <string>
#include <vector>

class Options {
public:
    Options() {} //default constructor
    Options(int argc, char** argv) : argc(argc), argv(argv) {} //member initialization list syntax
    std::string getopt(); //return valid options given, one by one
    int numopt(); //return number of given options in argv
    int valopt(); //return number of valid options in argv
    bool operator== (const Options& other) const; //non-mutating/inspection operator
    void setOptPossible(std::vector<std::string> optPossible);

private:
    void parseValidOpts(); //parse the given options for only valid ones

    //Pure virtual, must be implemented in subclasses
    virtual void parseGivenOpts() = 0; //parse the argv list for options given

protected:  //make accessible in derived class
    int argc = 0;
    char** argv = nullptr;
    int _numopt = 0; //num of options in argv
    int _valopt = 0; //num of given options that were valid

    //These types are now defined in subclasses as they vary
    std::vector<std::string> optPossible;  // defined by user, options program can respond to
    std::vector<std::string> optValid; //constructed from intersection of Given options and optstring
    std::vector<std::string> optGiven; //constructed from argv
};

#endif //U38_2_OPTIONS_H
