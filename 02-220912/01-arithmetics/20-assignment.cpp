#include <iostream>

int main() {
    int x = 0, y = 0;
    x = y = 20;
    std::cout << x << " " << y << "\n";

    if (x = 5) {  // modern compiler should emit warning
        std::cout << "x = " << x << "\n";
    }
}
