/* E3ISD1 Week 38/2 -- Exercise 8
 * Parse and shows valid options from command line with pattern like "-h" and "--help" (GNU style)
 *
 * This week we work with Polymorphism and Exception handling.
 *
 * Polymorphism
 * - A class that declares or inherits a virtual function is called a polymorphic class.
 *   -> So the Options class is polymorphic to its two derived classes.
 *   -> It declares pure virtual functions that are only implemented in derived classes.
 *   -> The Options base class is an _abstract base class_.
 * - To demonstrate polymorphism, we access the derived classes through pointers to a base class type.
 *
 * Exception handling
 * - Is implemented to handle the cases where no arguments are available.
 *
 * Last week we made two subclasses to Options for managing different options types:
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

    // Instantiate two different options objects (for demo)
    OptionsChars myOptionsChars(argc, argv);
    OptionsKeywords myOptionsKeywords(argc, argv);

    // We can now access them via polymorphism
    Options* opt1 = &myOptionsChars;
    Options* opt2 = &myOptionsKeywords;

    // DO WORK FOR CHAR STYLE OPTIONS
    opt1->setOptPossible(optChars); //we are now working through an Options object pointer (base class)

    std::cout << "Number of GIVEN CHAR options in command line: " << opt1->numopt() << std::endl;
    std::cout << "Number of VALID CHAR options in command line: " << opt1->valopt() << std::endl;

    for (int i = 0; i < opt1->valopt(); ++i) {
        std::cout << "Option " << i << ": " << opt1->getopt() << std::endl;
    }


    // REPEAT FOR KEYWORD STYLE OPTIONS
    opt2->setOptPossible(optKeywords);

    std::cout << "Number of GIVEN KEYWORD options in command line: " << opt2->numopt() << std::endl;
    std::cout << "Number of VALID KEYWORD options in command line: " << opt2->valopt() << std::endl;

    for (int i = 0; i < opt2->valopt(); ++i) {
        std::cout << "Option " << i << ": " << opt2->getopt() << std::endl;
    }

    return 0;
}