#include <iostream>
#include <vector>

int main() {
    // Extra reading: https://isocpp.org/blog/2012/11/on-vectorbool
    std::vector<bool> v{false, true, false};
    std::cout << v[0] << v[1] << v[2] << "\n";  // 010

    for ([[maybe_unused]] bool x : v) {  // copy as expected
        x = true;
    }
    std::cout << v[0] << v[1] << v[2] << "\n";  // 010

    for (auto x : v) {  // copy?
        x = true;
    }
    std::cout << v[0] << v[1] << v[2] << "\n";  // 111 ?!
}
