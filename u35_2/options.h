//
// Created by Janus Bo Andersen on 18/9/19.
//

#ifndef U35_2_OPTIONS_H
#define U35_2_OPTIONS_H

#include <iostream>
#include <string>

class Options {
public:
    //we will rely on the default constructor
    void checkOptions(const std::string& optStr);
    bool optA = false;
    bool optB = false;
};


#endif //U35_2_OPTIONS_H
