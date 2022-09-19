#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    // Extra reading: emplace_back() works as well, but involves implicit conversions
    // https://abseil.io/tips/112
    v.push_back(10);  // O(1) amortized
    v.push_back(20);
    std::cout << "v:";  // 10 20
    for (auto x : v) {
        std::cout << " " << x;
    }
    std::cout << "\n";

    v.pop_back();  // O(1) constant
    std::cout << "v:";  // 10
    for (auto x : v) {
        std::cout << " " << x;
    }
    std::cout << "\n";

    v.resize(5);
    std::cout << "v:";  // 10 0 0 0 0
    for (auto x : v) {
        std::cout << " " << x;
    }
    std::cout << "\n";

    v.resize(10, 2);  // 10 0 0 0 0 2 2 2 2 2
    std::cout << "v:";
    for (auto x : v) {
        std::cout << " " << x;
    }
    std::cout << "\n";

    v.resize(3, 123);  // 10 0 0
    std::cout << "v:";
    for (auto x : v) {
        std::cout << " " << x;
    }
    std::cout << "\n";

    v.clear();
    std::cout << v.size() << "\n";  // 0
}
