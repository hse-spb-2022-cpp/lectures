#include <iostream>

int main() {
    while (!std::cin.eof()) {  // Never do that: only checks whether EOF is already known.
        int x;
        std::cin >> x;  // Reads until the number is ended, not further.
        std::cout << x << "\n";
    }
}
