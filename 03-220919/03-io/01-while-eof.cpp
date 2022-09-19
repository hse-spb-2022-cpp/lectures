#include <iostream>

int main() {
    while (!std::cin.eof()) {  // Never do that.
        int x;
        std::cin >> x;
        std::cout << x << "\n";
    }
}
