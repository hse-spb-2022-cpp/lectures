#include <iostream>

int main() {
    int n = 5;
    // for (init; cond; update)
    for (int i = 0; i < n; i++) {
        std::cout << "i=" << i << "\n";
        // break;  // stop immediately
        // continue;  // continue to the next iteration (with update)
    }

    int j = 5;
    for (; j < 10; j += 2) {
        std::cout << "j=" << j << "\n";
    }

    for (unsigned k = 5; k >= 0; k--) {  // FIXME
        std::cout << "k=" << k << "\n";
    }
}
