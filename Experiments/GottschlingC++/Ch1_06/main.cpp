/* Test functionality from ch. 1.6 exception handling
 * Janus Bo Andersen, Sep 2019
 * */

#include <iostream>
#include <cstdlib>
#include <exception>


void test_func(void) {
    throw std::runtime_error("Ooops!");
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    try {
        test_func();
    } catch (...) { //catch-all      std::exception& e
        std::cerr << "Something went weirdly wrong... " << std::endl;  //e.what() <<
    }

    return EXIT_SUCCESS;
}