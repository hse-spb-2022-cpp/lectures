#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3};
    for (int value = 0; value < 10; value++) {
        bool found = false;
        for (std::size_t i = 0;; i++) {
            if (vec[i] == value) {
                found = true;
                // std::cout << i << "\n";
                break;
            }
        }
        // Always found? Enabling cout above changes behavior.
        // Try with Address Sanitizer.
        std::cout << "value=" << value << " found=" << found << "\n";
    }
}