/* E3ISD1 Week 37/2 -- Exercise 6
 * Parses and shows valid options from command line with pattern like "-a"
 * also conforming to a predefined list for the object.
 *
 * This week we overload a function and build an == operator for the object
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

    //make some other option objects (on the stack), with the same arguments
    Options equalOptions(argc, argv), differentOptions(argc, argv);
    equalOptions.setOptstring(optString);
    differentOptions.setOptstring("ABO");

    //test equality using the new == operator -- should be true
    if (*myOptions == equalOptions) {
        std::cout << "The equalOptions object has similar data." << std::endl;
    } else {
        std::cout << "The equalOptions object differs." << std::endl;
    }

    //test equality using the new == operator -- should be false
    if (*myOptions == differentOptions) {
        std::cout << "The differentOptions object has similar data." << std::endl;
    } else {
        std::cout << "The differentOptions object differs." << std::endl;
    }

    return 0;
}