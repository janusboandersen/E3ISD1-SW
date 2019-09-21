//
// Created by Janus Bo Andersen.
//

#include "Options.h"
#include <regex>
#include <algorithm>

//sets a vactor that defines valid options, then calls the parser for valid options
void Options::setOptPossible(std::vector<std::string> optPossible) {
    this->optPossible = optPossible; //set private member
    parseValidOpts(); //now parse and build set of valid options
    return; //done
}

//Parses given options and finds the valid ones
void Options::parseValidOpts() {

    //iterate over the options (allowed opts), and the ones found in Given are put in Valid vector
    std::vector<std::string>::iterator it; //iterator for find algo

    for (auto option: optPossible) {
        //check if the option was given at the command line
        it = std::find(begin(optGiven), end(optGiven), option); //where the c was found
        if (it != end(optGiven)) //if find did not reach end of vector, c was found
            optValid.push_back(option); // add the option as it was found in the Given
    }

    _valopt = optValid.size(); //set the number of Given options that were Valid

    return;
}


//return valid options given, one by one; returns '\0' when nothing else
std::string Options::getopt() {
    //pops elements from the Valid vector, if not empty
    std::string ret = "";

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
         && this->optPossible == other.optPossible   // started with identical vectors of possible
         && this->optGiven == other.optGiven     // command line options have been parsed (always true if above)
         && this->optValid == other.optValid     // cmd line options have been filtered with optstring (same)
         && this->_numopt == other._numopt       // this should always be true as a consequence of above
         && this->_valopt == other._valopt) {    // same...
        return true; //similar
    } else {
        return false; //not similar
    }
}