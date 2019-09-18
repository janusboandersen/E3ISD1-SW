//
// Created by Janus Bo Andersen on 18/9/19.
//

#include "Options.h"

bool Options::isPresent(char c) {

    //concatenate chars to get "-a", and then compare with argument list
    std::string searchStr {"-"};
    searchStr.push_back(c);

    // here we just do an ugly linear search
    // start search from one, don't need to check executable
    // TODO: Do better than a linear search
    for (int i = 1; i < argc; ++i) {
        if (argv[i] == searchStr)
            return true; //found option
    }
    return false; //not found
}