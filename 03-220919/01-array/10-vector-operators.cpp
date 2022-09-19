#include <iostream>
#include <vector>

int main() {
    std::vector v1{1, 2, 3}, v2{4, 5};

    std::cout << "v2:";
    for (int x : v2) {
        std::cout << ' ' << x;
    }
    std::cout << '\n';
    std::cout << (v1 == v2) << (v1 < v2) << (v1 > v2) << '\n';  // 010: lexicographical comparison: 1 < 4

    v1 = v2;  // O(n + m), copies all elements, v1 and v2 are still independent
    std::cout << "v2:";
    for (int x : v2) {
        std::cout << ' ' << x;
    }
    std::cout << '\n';
    std::cout << (v1 == v2) << (v1 < v2) << (v1 > v2) << '\n';  // 100

    v1[0] = 100;
    std::cout << "v2:";
    for (int x : v2) {
        std::cout << ' ' << x;
    }
    std::cout << '\n';
    std::cout << (v1 == v2) << (v1 < v2) << (v1 > v2) << '\n';  // 001

    // And others: https://en.cppreference.com/w/cpp/container/vector
}
