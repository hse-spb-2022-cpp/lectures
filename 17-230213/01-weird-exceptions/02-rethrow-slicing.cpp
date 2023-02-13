#include <exception>
#include <iostream>
#include <stdexcept>

void foo() {
    try {
        throw std::runtime_error("Hello World");
    } catch (std::exception &a) {
        // throw a;  // oops, slicing
        throw;  // no slicing
    }
}

int main() {
    try {
        foo();
    } catch (std::exception &e) {
        std::cout << "caught in main(): " << e.what() << "\n";
    }
}
