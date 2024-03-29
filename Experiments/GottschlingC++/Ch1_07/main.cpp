/* IO ch. 1.8
 * Janus Bo Andersen, Sep 2019
 * */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <string>

//testing out inserter and extractor
void area() {
    std::cout << "Hello, World! Enter width and length" << std::endl;

    //test twice use of the extraction operator
    int width = 0, length = 0;
    std::cin >> width >> length;
    int area = width*length;
    std::cout << "Area: " << (area) << std::endl;

    //write the area to a file
    std::ofstream myfile;
    myfile.open("area.txt");
    myfile << area << std::endl;
    myfile.close(); //we close explicitly here, but RAII is in effect...
}

//testing out the stringstream concept
void write_something(std::ostream& os) {
    os << "Hi stream, did you know that 3*3 is " << 3*3 << std::endl;
}

void test_three_streamtypes() {
    std::ofstream myfile("example.txt");
    std::stringstream mysstream;

    write_something(std::cout);
    write_something(myfile);
    write_something(mysstream);

    //show the contents of the stringstream
    std::cout << "mysstream is: " << mysstream.str(); //newline contained

}

void test_iomanip() {
    double pi = M_PI;

    int old_precision = std::cout.precision();

    std::cout << "pi is " << pi << '\n';
    std::cout << "pi is " << std::setprecision(16) << pi << '\n'; //floating point precision
    std::cout << "pi is " << std::setw(30) << pi << '\n';   //character width

    //test fill and alignment
    std::cout << "pi is " << std::setfill('-') << std::left << std::setw(30) << pi << '\n';

    //manipulate by setting flags
    std::cout.setf(std::ios_base::showpos);
    std::cout << "pi is " << std::scientific << pi << '\n';

    //other number formats
    std::cout << "63 oct is " << std::oct << 63 << '\n';
    std::cout << "63 hex is " << std::hex << 63 << '\n';
    std::cout << "63 dec is " << std::dec << 63 << '\n';

    //outputting boolean values nicely
    std::cout << "pi < 3 is " << (pi < 3) << '\n';
    std::cout << "pi < 3 is " << std::boolalpha << (pi < 3) << '\n';

    //reset to standard
    std::cout.unsetf(std::ios_base::adjustfield | std::ios_base::basefield |
                             std::ios_base::floatfield | std::ios_base::showpos | std::ios_base::boolalpha);
    std::cout.precision(old_precision);
}

void test_errors() {

    //try to open a file that doesn't exist
    std::ifstream infile("idontexist.txt");

    int i;
    double d;

    //try to read from the nonexistent file
    infile >> i >> d;

    std::cout << "i is " << i << " and d is " << d << std::endl;
    infile.close();
    
}

void robuster_iohandler(void) {
    std::ifstream infile;
    std::string filename{"some_missing_file.xyz"};

    bool opened = false;

    while (!opened) {
        infile.open(filename); //try to open
        if (infile.good()) {
            opened = true;  //check error code and set bool
        } else {
            std::cout << "The file '" << filename << "' doesn't exist, give me a new file: ";
            std::cin >> filename;
        }
    }

    int i;
    double d;

    //get from the now opened file
    infile >> i >> d;

    if (infile.good()) {
        std::cout << "i is " << i << ", d is " << d << '\n';
    } else {
        std::cout << "Could not correctly read the contents of the file." << std::endl;
    }
    infile.close();
}

void exception_enabled_io(void) {

    //enable exceptions on standard streams
    std::cin.exceptions(std::ios_base::badbit | std::ios_base::failbit);
    std::cout.exceptions(std::ios_base::badbit | std::ios_base::failbit);

    //a file that doesnt exist
    std::ifstream infile("f.txt");

    //exceptions only enabled after opening
    infile.exceptions(std::ios_base::badbit | std::ios_base::failbit); //error is thrown now

}

int main() {

    //test I/O
    //area();

    //try to write to three different kinds of streams
    //test_three_streamtypes();

    //test I/O formatting wit iomanip
    //test_iomanip();

    //test I/O errors
    //test_errors();  //Notice: streams do NOT throw errors, we have to check error flags

    //try a bit robuster
    //robuster_iohandler();

    //try with exceptions enabled
    exception_enabled_io();

    return 0;
}