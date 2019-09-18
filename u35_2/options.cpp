//
// Created by Janus Bo Andersen on 18/9/19.
//

#include "options.h"

void Options::checkOptions(const std::string& optStr) {

    /* Only for debug
    std::cout << "Checking string: " << optStr << std::endl;
    std::cout << optStr.compare("optionA") << std::endl;
    std::cout << optStr.compare("optionB") << std::endl;
    */

    //Perform two string comparisons to determine which options are set, using overloaded operator==
    if (optStr == "optionA") optA = true;
    if (optStr == "optionB") optB = true;

}