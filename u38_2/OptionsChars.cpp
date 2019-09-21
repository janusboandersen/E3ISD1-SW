//
// Created by Janus Bo Andersen.
//

#include "OptionsChars.h"
#include <regex>
#include <algorithm>

//parse argv for command line options
void OptionsChars::parseGivenOpts() {
    //Regex to find options like "-a"
    std::regex re("^-([a-zA-Z])\\b"); //pattern -a .. -Z, capture is only the char \\b is boundary
    std::smatch match;
    std::string str;

    for (int i = 0; i < argc; ++i) {
        str = argv[i]; //convert to searchable string
        std::regex_search(str, match, re); //Perform regex to check if a string in argv is a valid option

        //add a found option to Given vector
        if (!match.empty()) {
            optGiven.push_back( std::string(match[1]) ); //push match 1 onto vector
        }
    }

    //set the number of given valid options
    _numopt = optGiven.size();

    return;
}