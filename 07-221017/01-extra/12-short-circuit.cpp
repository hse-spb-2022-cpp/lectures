#include <iostream>
#include <vector>

bool f(bool x) {
    std::cout << "f(" << x << ")\n";
    return x;
}

bool g(bool x) {
    std::cout << "g(" << x << ")\n";
    return x;
}

int main() {
    // short circuit
    f(false) && g(false);
    std::cout << "====\n";

    f(false) && g(true);
    std::cout << "====\n";

    f(true) && g(false);
    std::cout << "====\n";

    f(true) && g(true);
    std::cout << "====\n";

    std::vector v;
    if (v.size() >= 10 && v[9] == 123) {  // safe!
        std::cout << "something\n";
    }
    if (v[9] == 123 && v.size() >= 10) {  // UB!
        std::cout << "something\n";
    }

    // similarly for ||
    // only for non-overloaded && and ||
}
