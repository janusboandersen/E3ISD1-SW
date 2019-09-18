//
// Created by Janus Bo Andersen on 18/9/19.
//

#ifndef U36_1_OPTIONS_H
#define U36_1_OPTIONS_H

#include <iostream>
#include <string>
#include <set>
#include <vector>

class Options {
public:
    Options() {} //default constructor
    Options(int argc, char** argv) : argc(argc), argv(argv) {parseGivenOpts();} //member initialization list syntax
    ~Options() {} //default destructur
    void setOptstring(std::string optString); //sets a string that defines valid options
    char getopt(); //return valid options given, one by one
    int numopt(); //return number of given options in argv
    int valopt(); //return number of valid options in argv

private:
    void parseGivenOpts(); //parse the argv list for options given
    void parseValidOpts(); //parse the given options for only valid ones
    int argc = 0;
    char** argv;
    std::string optString; //from user
    std::vector<char> optValid; //constructed from intersection of Given options and optstring
    std::vector<char> optGiven; //constructed from argv
    int _numopt = 0; //num of options in argv
    int _valopt = 0; //num of given options that were valid
};

#endif //U36_1_OPTIONS_H
