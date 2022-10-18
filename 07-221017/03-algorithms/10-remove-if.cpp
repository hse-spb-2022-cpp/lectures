#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector v{10, 11, 12, 13, 14, 15, 16, 17, 18};
    auto new_end = std::remove_if(v.begin(), v.end(), [](int x) {
        return x % 3 == 0;
    });
    std::cout << new_end - v.begin() << "\n";

    for (int x : v) {
        std::cout << " " << x;
    }
    std::cout << "\n";
}
