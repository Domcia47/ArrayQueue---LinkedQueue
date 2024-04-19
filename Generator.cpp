#include <iostream>
#include <string>
#include <ctime>
//#include "ArrayStack.hpp"

int main(int argc, const char *argv[]) {
    // initialize the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // check if an argument was provided when running the program
    if (argc < 2) {
        std::cerr << "No arguments." << std::endl;
        return 1;
    }

    std::string argument = argv[1]; // read the argument provided when running the program into a variable

    int n; // variable to store the number of operations to generate
    n = std::stoi(argument); // assign the variable the argument converted from string to int

    // check if the argument meets the task conditions
    if(n > 1000000){
        std::cout << "Argument out of range." << std::endl;
        return 1;
    }

    // print the number of generated operations for the Stack.cpp program
    std::cout << n;

    for (int i = 0; i < n; ++i) {
        int operation = std::rand() % 3; // generate a random operation type: 0, 1, or 2

        if (operation == 0) {
        // for randomly generated 0, operation type "D"
            std::cout << "D" << std::endl;
            
        } else if (operation == 1) {
        // for randomly generated 1, operation type "S"
            std::cout << "S " << std::endl;
        } 
        else {
        // for randomly generated 2, operation type "A x"
            int value = std::rand() % 1000001;  // generate a random natural number from 0 to 10^6
            std::cout << "A " << value << std::endl; // print the operation A x
        }
    }

    return 0;
}
