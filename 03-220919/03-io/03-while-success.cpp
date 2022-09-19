#include <iostream>

int main() {
    while (true) {
        int x;
        if (!(std::cin >> x)) {
            break;
        }
        std::cout << x << "\n";
    }
}
