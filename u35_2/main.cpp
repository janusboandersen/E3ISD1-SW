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

    //output what we received...
    std::cout << "Program started with: " << argv[0] << " " << argv[1]
                << " " << argv[2] << "..." << std::endl;

    //convert char arrays to strings and store in a vector
    std::vector<std::string> args;
    args.push_back( std::string(argv[1]) );
    args.push_back( std::string(argv[2]) );

    Options myOptions; //make new options object

    //check options using member function and string's constructor
    myOptions.checkOptions( args[0] ); //check the first argument
    myOptions.checkOptions( args[1] ); //check the second argument

    //Output the results
    if (myOptions.optA) {
        std::cout << "Option A was set" << std::endl;
    }

    if (myOptions.optB) {
        std::cout << "Option B was set" << std::endl;
    }

    return 0;
}