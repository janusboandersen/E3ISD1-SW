/*
 * E3ISD1 Week 35/1
 * Simple input/output in C++
 * Janus Bo Andersen, 2019
 * */

#include <iostream>
#include <vector>
#include <string>

int main() {

    const unsigned min = 1;
    const unsigned max = 5;

    //Define some quotes to give the user
    std::vector<std::string> quotes {"Quote 1","Quote 2","Quote 3","Quote 4","Quote 5"};

    // Get user input
    bool valid = false; //turns true on valid user input
    unsigned q_no = {0u}; //quote number - only unsigned numbers

    do {
        std::cout << "Hello, please enter a valid number from 1-5 to get a quote!" << std::endl;
        std::cin >> q_no; //attempt to extract
        if (std::cin.good()) { //no error in extraction
            valid = (q_no >= min && q_no <= max) ? true : false; //test input validity
        } else { //some error in extraction
            std::cin.clear();             //clear error flags
            std::cin.ignore(10000, '\n'); //ignore up to next newline
        }
    } while (!valid);

    //Give user some quote from a valid choice
    std::cout << quotes[q_no - 1] << std::endl; //offset by 1 to translate from natural numbers

    return 0;
}