/* E3ISD1 Week 38/1 -- Exercise 7
 * Parse and shows valid options from command line with pattern like "-h" and "--help" (GNU style)
 *
 * This week we make two subclasses for managing options:
 *  - one class for single hyphen and character style ("-h") -> OptionsChars
 *  - and another for double hyphen and keyword style ("--help") -> OptionsKeywords.
 *
 * Both classes inherit some methods from the parent Options class, while other methods there are pure virtual
 * and must be implemented in the subclasses.
 *
 * Ideally, we'd have one class that could handle both, but this way demonstrates inheritance.
 *
 * From previous weeks, the following has been refactored:
 *  - possible options are always set in vectors of strings, no longer in strings (similar behavior) among the two types.
 *  -
 *
 * Janus Bo Andersen, Sep 2019
 *
 * */

#include <iostream>
#include <string>
#include "Options.h"
#include "OptionsChars.h"

int main(int argc, char* argv[]) {

    std::vector<std::string> optChars {"a", "b", "o"}; //only accept -a -b -o options
    std::vector<std::string> optKeywords {"alpha", "beta", "omega"}; //only accept --alpha --beta --omega options

    OptionsChars myOptionsChars(argc, argv);
    myOptionsChars.setOptPossible(optChars);

    std::cout << "Number of GIVEN CHAR options in command line: " << myOptionsChars.numopt() << std::endl;
    std::cout << "Number of VALID CHAR options in command line: " << myOptionsChars.valopt() << std::endl;

    for (int i = 0; i < myOptionsChars.valopt(); ++i) {
        std::cout << "Option " << i << ": " << myOptionsChars.getopt() << std::endl;
    }

    return 0;
}