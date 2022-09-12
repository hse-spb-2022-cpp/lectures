#include <iostream>

int main() {
    int n;
    std::cin >> n;

    // Shorter
    if (n < 10)
        std::cout << "less than 10\n";
    else
        std::cout << "greater or equal than 10\n";

    // Harder to screw up
    if (n == 10) {  // careful: ==, not =
        std::cout << "n is \n";
        std::cout << "equal to ten\n";
    } else {
        std::cout << "not equal to ";
        std::cout << "ten\n";
    }

    // If-else emulation
    if (n < 10) {
        std::cout << "n < 10\n";
    } else if (n > 10) {
        std::cout << "n > 10\n";
    } else {
        std::cout << "n == 10\n";
    }
}
