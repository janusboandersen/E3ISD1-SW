/*
 * E3ISD1 Week 35/2 -- Exercise 2
 * Options class: Accept command line options, and print the options set
 * Janus Bo Andersen, 2019
 * */

#include <iostream>
#include <vector>
#include <string>
#include "options.h"

int main(int argc, char* argv[]) {

    std::vector<std::string> args;
    Options myOptions; //make new options object

    //output what we received... While converting to modern types... and checking options
    if (argc > 1) {
        std::cout << "Program started with: ";

        //loop over any options, omit the executable
        for (unsigned i = 1; i < argc; ++i) {
            std::cout << argv[i] << " ";

            //convert char arrays to strings using string's constructor, and store in a vector
            args.push_back( std::string(argv[i]) ); //probably some copying going on here...

            //check options using the member function
            myOptions.checkOptions( args[i-1] ); //check the converted argument
        }
        std::cout << std::endl;
    } else {
        std::cout << "Program started without options." << std::endl;
    }

    //Output the results
    if (myOptions.optA) {
        std::cout << "Option A was set" << std::endl;
    }

    if (myOptions.optB) {
        std::cout << "Option B was set" << std::endl;
    }

    return 0;
}