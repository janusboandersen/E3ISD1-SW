/*
 * Ch. 1.8 Arrays, pointers and references
 * Janus Bo Andersen, Sep 2019
 */

#include <iostream>
#include <memory>
#include <vector>
#include <cassert>

//function returns a new unique_ptr, and ownership is moved on return
std::unique_ptr<double> f() {
    return std::unique_ptr<double >{new double};
}

//function returns a shared pointer, can be copied many times
std::shared_ptr<double> g() {
    std::shared_ptr<double> p1{new double};
    std::shared_ptr<double> p2{new double}, p3 = p2; //makes two shared that both point to the same memory

    std::cout << "p3.use_count() = " << p3.use_count() << std::endl;
    return p3;
}

//function to add vectors using references
void vector_add(const std::vector<float>& v1, const std::vector<float>& v2, std::vector<float>& s) {
    assert(v1.size() == v2.size());
    assert(v1.size() == s.size());

    for (unsigned i = 0; i < v1.size(); ++i) {
        s[i] = v1[i] + v2[i];
    }
}

//more natural form returns a vector (copyable), but potentially more "expensive"
std::vector<float> vector_add(const std::vector<float>& v1, const std::vector<float>& v2) {
    assert(v1.size() == v2.size());
    std::vector<float> s(v1.size()); //guarantees right size
    for (unsigned i = 0; i < v1.size(); ++i) {
        s[i] = v1[i] + v2[i];
    }
    return s;
}

int main() {
    std::cout << "Hello, World! Let's do Smart Pointers" << std::endl;

    std::unique_ptr<double> dp3;
    std::cout << "Pointer data before assignment " << dp3.get() << std::endl; //should be a nullptr address
    dp3 = f(); //assign by move

    std::cout << "Pointer data after assignment " << dp3.get() << std::endl; //should be some real address

    //Try the unique_ptr for arrays
    std::unique_ptr<double[]> da{new double[3]};

    for (unsigned i = 0; i < 3; ++i) {
        da[i] = i + 2; //notice the syntax! ...like a stack-allocated array
    }

    std::shared_ptr<double> p = g(); //we make a shared_ptr
    std::cout << "p.use_count() = " << p.use_count() << std::endl; //p2 and p3 are dead, and only p is referring to mem

    //an even better way to make a shared_ptr
    auto p1 = std::make_shared<double>(); //auto deduction plus manager and count are stored together in memory

    //playing with C++ vectors

    //not very compact
    std::vector<float> v(3), w(3);
    v[0] = 1; v[1] = 2; v[3] = 3;
    w[0] = 7; w[1] = 8; w[3] = 9;

    //more compact
    std::vector<float> x = {1,2,3}, y = {7,8,9};

    //try to add using the all-references function
    std::vector<float> sum1(3);
    vector_add(x, y, sum1);

    //try to add using a more natural form
    std::vector<float> sum2 = vector_add(x, y); //trying to use function overloading

    std::cout << "vector sum = (" << sum2[0] << ", " << sum2[1] << ", " << sum2[2] << ")." << std::endl;

    return 0;
}