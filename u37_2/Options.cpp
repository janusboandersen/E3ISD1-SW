//
// Created by Janus Bo Andersen.
//

#include "Options.h"
#include <regex>
#include <algorithm>
#include <sstream>

//parse argv for command line options
void Options::parseGivenOpts() {
    //Regex to find options like "-a"
    std::regex re("^-([a-zA-Z])\\b"); //pattern -a .. -Z, capture is only the char \\b is boundary
    std::smatch match;
    std::string str;
    std::stringstream s;
    char c;

    for (int i = 0; i < argc; ++i) {
        str = argv[i]; //convert to searchable string

        //Perform regex to check if a string in argv is a valid option
        std::regex_search(str, match, re);

        //add a found option to Given vector
        if (!match.empty()) {
            s <<  match[1]; //insert match group 1 ([a-zA-Z]) into stringstream
            s >> c; // extract a char from stringstream
            optGiven.push_back( c ); //push char onto vector
        }
    }

    //set the number of given valid options
    _numopt = optGiven.size();

    return;
}

void Options::parseValidOpts() {

    //iterate over the options string (allowed opts), and the ones found in Given are put in Valid vector
    std::vector<char>::iterator it; //iterator for find algo

    for (auto c: optString) {
        //check if the option was given at the command line
        it = std::find(begin(optGiven), end(optGiven), c); //where the c was found
        if (it != end(optGiven)) //if find did not reach end of vector, c was found
            optValid.push_back(c); // add the option as it was found in the Given
    }

    _valopt = optValid.size(); //set the number of Given options that were Valid

    return;
}

//sets a string that defines valid options
//also calls the parser for valid options
void Options::setOptstring(std::string optString) {

    //set private member
    this->optString = optString;

    //now parse and build set of valid options
    parseValidOpts();

    return; //done
}

//return valid options given, one by one; returns '\0' when nothing else
char Options::getopt() {
    //pops elements from the Valid vector, if not empty
    char ret = '\0';

    if (!optValid.empty()) {
        ret = optValid.back(); //take the last item
        optValid.pop_back(); //remove the item
    }
    return ret;
}

//return number of possible options in argv
int Options::numopt() {
    //just an OOP getter...
    return _numopt;
}


//return number of valid options in argv
int Options::valopt() {
    //just an OOP getter...
    return _valopt;
}

//non-mutating/inspection operator
//compares all data items for this and other: this==other
bool Options::operator== (const Options& other) const {

    //comparison list is very redundat, only first three needed... Others are then invariants.
    if (    this->argc == other.argc             // same command line argument length
         && this->argv == other.argv             // same command line argument mem location
         && this->optString == other.optString   // started with identical strings
         && this->optGiven == other.optGiven     // command line options have been parsed (always true if above)
         && this->optValid == other.optValid     // cmd line options have been filtered with optstring (same)
         && this->_numopt == other._numopt       // this should always be true as a consequence of above
         && this->_valopt == other._valopt) {    // same...
        return true; //similar
    } else {
        return false; //not similar
    }
}