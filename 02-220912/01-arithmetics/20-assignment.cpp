#include <iostream>

int main() {
    int x = 0, y = 0;
    x = y = 20;
    std::cout << x << " " << y << "\n";

    std::cout << (x = 15) << "\n";  // 15, but what for?
    std::cout << x << "\n";         // 15

    if (x = 5) {  // modern compiler should emit warning
        std::cout << "x = " << x << "\n";
    }
}
