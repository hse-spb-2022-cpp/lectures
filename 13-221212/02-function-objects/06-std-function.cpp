#include <cmath>
#include <functional>
#include <iostream>

struct CloserTo {
    int center;

    bool operator()(int a, int b) const {
        return std::abs(a - center) < std::abs(b - center);
    }
};

struct BigFunctor {
    long long a, b, c, d, e, f, g, h, i;

    bool operator()(int lhs, int rhs) const {
        return lhs < rhs;
    }
};

char not_exact(char a, char b) {
    return a + b;
}

int main() {
    std::function<bool(int, int)> cmp = CloserTo{10};
    std::cout << cmp(3, 200) << "\n";  // 1
    std::cout << sizeof(CloserTo) << " " << sizeof(cmp) << "\n";

    cmp = BigFunctor();
    std::cout << cmp(3, 4) << "\n";  // 1
    std::cout << sizeof(BigFunctor) << " " << sizeof(cmp) << "\n";

    int x = 10;
    cmp = [&](int a, int b) {
        return a + x < b + x;
    };
    std::cout << cmp(100, 101) << "\n";  // 1
    std::cout << sizeof(cmp) << "\n";

    cmp = not_exact;  // Also OK. Hmmm.
    std::cout << cmp(10, 20) << "\n";  // 1
    
    // Type Erasure (need basic templates): https://www.youtube.com/watch?v=tbUCHifyT24
}
