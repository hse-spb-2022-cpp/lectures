#include <iostream>

int main() {
    int n = 5;
    while (n-- > 0) {  // while (n --> 0)
        std::cout << n << "\n";
    }
    std::cout << "after loop: " << n << "\n";

    while (true) {
        int v;  // Please do declare variables inside the loop, it's free!
        std::cin >> v;
        std::cout << "v=" << v << "\n";
    }
}
