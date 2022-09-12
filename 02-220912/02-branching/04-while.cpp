#include <iostream>

int main() {
    int n = 5;
    while (n-- > 0) {  // while (n --> 0)
        std::cout << n << "\n";
    }
    std::cout << "after loop: " << n << "\n";

    while (true) {
        int v;  // Please do declare variables inside the loop, it's free!
        if (!(std::cin >> v)) {
            break;
        }
        std::cout << "v=" << v << "\n";
    }

    do {
        std::cout << "infinite loop\n";
    } while (true);
}
