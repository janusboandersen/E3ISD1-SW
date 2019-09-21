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
 * - Is implemented to handle the cases where no more options arguments are available to "getopt".
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
 *  - Derived objects referred to via base class pointers.
 *
 * Janus Bo Andersen, Sep 2019
 *
 * */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Options.h"
#include "OptionsChars.h"
#include "OptionsKeywords.h"

int main(int argc, char* argv[]) {

    std::vector<std::string> optChars {"a", "b", "o"}; //only accept -a -b -o options
    std::vector<std::string> optKeywords {"alpha", "beta", "omega"}; //only accept --alpha --beta --omega options

    // Instantiate two different Options-derived objects (for demo)
    OptionsChars myOptionsChars(argc, argv);
    OptionsKeywords myOptionsKeywords(argc, argv);

    // We can now access them via polymorphism
    std::vector<Options*> opt(2); //vector holds two pointers to options objects
    opt[0] = &myOptionsChars;
    opt[1] = &myOptionsKeywords;

    // We are now working through an Options object pointer (base class)
    opt[0]->setOptPossible(optChars);
    opt[1]->setOptPossible(optKeywords);

    // And we can work on all the objects in the same way, looping over them
    for (auto o: opt) {
        std::cout << o->valopt() << " out of " << o->numopt() << " command line args were valid." << std::endl;

        // Display the options contained in the object, popped one by one
        for (int i = 0; i < o->valopt(); ++i) {
            std::cout << "Option set no. " << i << ": " << o->getopt() << std::endl;
        }
    }

    // To demo exception handling, try to get an option now that the objects are fully popped
    try {
        std::cout << opt[0]->getopt() << std::endl;  // should throw an error

    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl; // Get error description
    }

    return 0;
}