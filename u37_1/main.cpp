/* E3ISD1 Week 37/1 -- Exercise 5
 * Parses and shows valid options from command line with pattern "-a"
 * also conforming to a predefined list.
 * !! This week we allocate on the heap !!
 * Janus Bo Andersen, Sep 2019
 * */

#include <iostream>
#include <string>
#include "Options.h"

int main(int argc, char* argv[]) {

    std::string optString {"abo"}; //only accept -a -b -o options

    //allocate object on the heap, modern C++ style
    auto myOptions = std::make_unique<Options>(argc, argv); //make a unique smart pointer (RAII)

    myOptions->setOptstring(optString); //set the allowed options in the object, also parses them

    std::cout << "Number of GIVEN options in command line: " << myOptions->numopt() << std::endl;
    std::cout << "Number of VALID options in command line: " << myOptions->valopt() << std::endl;

    //popping the options one by one...
    for (unsigned i = 0; i < myOptions->valopt(); ++i) {
        std::cout << "Valid option was set: " << myOptions->getopt() << std::endl;
    }

    return 0;
}