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
 *  - only the regex differs between the two subclasses, and this could just be set as a param.
 *
 * From previous weeks, the following has been refactored:
 *  - possible options are always set in vectors of strings, no longer in strings (similar behavior) among the two types.
 *
 * Janus Bo Andersen, Sep 2019
 *
 * */

#include <iostream>
#include <string>
#include "Options.h"
#include "OptionsChars.h"
#include "OptionsKeywords.h"

int main(int argc, char* argv[]) {

    std::vector<std::string> optChars {"a", "b", "o"}; //only accept -a -b -o options
    std::vector<std::string> optKeywords {"alpha", "beta", "omega"}; //only accept --alpha --beta --omega options

    // DO WORK FOR CHAR STYLE OPTIONS

    OptionsChars myOptionsChars(argc, argv);
    myOptionsChars.setOptPossible(optChars);

    std::cout << "Number of GIVEN CHAR options in command line: " << myOptionsChars.numopt() << std::endl;
    std::cout << "Number of VALID CHAR options in command line: " << myOptionsChars.valopt() << std::endl;

    for (int i = 0; i < myOptionsChars.valopt(); ++i) {
        std::cout << "Option " << i << ": " << myOptionsChars.getopt() << std::endl;
    }


    // REPEAT FOR KEYWORD STYLE OPTIONS

    OptionsKeywords myOptionsKeywords(argc, argv);
    myOptionsKeywords.setOptPossible(optKeywords);

    std::cout << "Number of GIVEN KEYWORD options in command line: " << myOptionsKeywords.numopt() << std::endl;
    std::cout << "Number of VALID KEYWORD options in command line: " << myOptionsKeywords.valopt() << std::endl;

    for (int i = 0; i < myOptionsKeywords.valopt(); ++i) {
        std::cout << "Option " << i << ": " << myOptionsKeywords.getopt() << std::endl;
    }

    return 0;
}