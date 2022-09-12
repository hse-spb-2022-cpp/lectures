#include <iostream>

int main() {
    int n = 5;
    // for (init; cond; update)
    for (int i = 0; i < n; i++) {
        std::cout << "i=" << i << "\n";
        if (i == 3) {
            std::cout << "  break\n";
            break;  // stop immediately
        }
        if (i % 2 == 1) {
            std::cout << "  continue\n";
            continue;  // continue to the next iteration (with update)
        }
        std::cout << "  end of iteration\n";
    }
    // std::cout << i << "\n";  // compilation error: `i` is dead
    std::cout << "loop done\n";

    // more complicated
    int j = 5;
    for (; j < 10; j += 2) {
        std::cout << "j=" << j << "\n";
    }
}
