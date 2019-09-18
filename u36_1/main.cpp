/* E3ISD1 Week 36/1 -- Exercise 3
 * Take options from command line as e.g. -a -b -o
 * Janus Bo Andersen, Sep 2019
 * TODO: Improve search over linear search
 * */

#include <iostream>
#include <vector>
#include "Options.h"

int main(int argc, char* argv[]) {

    std::vector<char> searchOptions {'a', 'b', 'o'}; // we want to seach among these possibilities
    Options myOptions(argc, argv); //create new Options object, passing the command line args

    //Show what we received... Just to be nice ;)
    if (argc > 1) {
        std::cout << "Program started with: ";
        //loop over option flags, omit the executable
        for (unsigned i = 1; i < argc; ++i) {
            std::cout << argv[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Program started without options." << std::endl;
    }

    //check the options
    for(auto c: searchOptions) {
        if (myOptions.isPresent(c))
            std::cout << "Option " << c << " was set on the command line." << std::endl;
    }

    return 0;
}