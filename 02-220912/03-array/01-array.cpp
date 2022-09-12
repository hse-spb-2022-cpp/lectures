#include <cstddef>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1, v2;       // empty dynamic arrays
    std::vector<int> v3(10);       // 10 zeros
    std::vector<int> v4{1, 2, 3};  // 3 elements: 1, 2, 3

    std::cout << "v1:";
    for (int i = 0; i < static_cast<int>(v1.size()); i++) {
        std::cout << " " << v1[i];
    }
    std::cout << "\n";

    std::cout << "v2:";
    for (std::size_t i = 0; i < v2.size(); i++) {
        std::cout << " " << v2[i];
    }
    std::cout << "\n";

    std::cout << "v3:";
    for (int value : v3) {  // range-based-for
        std::cout << " " << value;
    }
    std::cout << "\n";

    std::cout << "v4:";
    for (auto value : v4) {
        std::cout << " " << value;
    }
    std::cout << "\n";
}
