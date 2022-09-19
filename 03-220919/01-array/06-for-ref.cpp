#include <iostream>
#include <vector>

int main() {
    std::vector v{1, 2, 3};

    for (auto x : v) {
        x += 10;  // modifies a copy
    }
    std::cout << "v:";
    for (auto x : v) {
        std::cout << ' ' << x;
    }
    std::cout << '\n';

    // for (int &x : v) {  // also ok
    for (auto &x : v) {  // & is 'reference' when attached to a type
        x += 10;
    }

    std::cout << "v:";
    // for (const int &x : v)  // also ok
    for (const auto &x : v) {  // 'const-reference', cannot be modified
        // x += 10;  // compilation error
        std::cout << ' ' << x;
    }
    std::cout << '\n';
}
