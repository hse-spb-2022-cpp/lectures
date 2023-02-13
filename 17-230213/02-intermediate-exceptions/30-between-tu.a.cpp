#include <exception>
#include <iostream>

void foo();

int main() {
    try {
        foo();
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
}
