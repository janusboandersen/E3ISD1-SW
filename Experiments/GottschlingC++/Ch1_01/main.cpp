/*
 * Using CLion and CMake to testing C++11/17 functionality from Chapters 1.1-1.5
 * Janus Bo Andersen, Sep. 2019
 * */

#include <iostream>
#include <string>
#include <complex>
#include <vector>

//pass by reference incrementor
void increment(int& x) {
    x++;
}

//default arguments
double root(double x, int degree = 2) {
    return pow(x, 1.0 / (double) degree );
}

//testing inlining
inline double square(const double& x) {
    return x * x;
}

//testing function overloading
int divide(int a, int b) {
    return a/b;
}

float divide(float a, float b) {
    return a/b;
}

int main() {
    std::cout << "The answer to the Ultimate question of Life,\n"
              << "the Universe, and Everything is:"
              << std::endl << 6 * 7 << std::endl;

    auto i = 2 + 5; //try automatic type deduction
    std::cout << i << std::endl;

    std::string s2 = "In C++ better do like this";
    std::cout << s2 << std::endl;

    std::complex<float> z(2,3); //try complex
    std::cout << "Twice my z=" << 2.0f * z << std::endl; //will cause an error if the wrong kind of literal

    long l = {1234567890123}; //try out uniform, non narrowing initialization
    //int j = {3.14}; // should cause a narrowing error for loss of digits

    //std::cout << (3+5)++ << std::endl; //error, not an LValue (not assignable / addressable)

    auto p = 4;     // explore prefix and postfix operators in C++
    std::cout << (p)++ << std::endl;    //returns the old value
    std::cout << (p) << std::endl;      //updated value
    std::cout << ++(p) << std::endl;    //returns the new value

    double v[] = {2., 4., 6.};
    for (int i = 0; i < 3; ++i) {
        std::cout << "v[" << i << "] = " << v[i] << std::endl;
    }

    // Taylor series for the exponential function up to the tenth term
    // e^2 = ...
    double x = 2.0, xn = 1.0, exp_x = 1.0;
    unsigned long fac = 1;
    for (unsigned long i = 1; i <= 10; ++i) {
        xn *= x;
        fac *= i;
        exp_x += xn / fac;
        std::cout << "step " << i << ": e^x is " << exp_x << '\n';
    }

    // Range-based (Iterator based) for loop
    int primes[] = {2,3,5,7,11,13,17,19};
    for (int i: primes) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    int incr = 9;
    increment(incr);
    std::cout << "Increment 9 to get " << incr << std::endl;

    std::vector<int> alpha = {1, 2, 3};
    //std::cout << "alpha = " << alpha << std::endl;

    //testing default arguments
    std::cout << "Square root of 2 is: " << root(2.0) << std::endl;
    std::cout << "Cube root of 27: " << root(27.0, 3) << std::endl;

    //testing inlining
    std::cout << "Square of 27: " << square(27.0) << std::endl;

    //testing function overloading
    std::cout << "3/27: " << divide(3, 27) << std::endl;
    std::cout << "3.0/27.0: " << divide(3.0f, 27.0f) << std::endl;



    return 0;
}