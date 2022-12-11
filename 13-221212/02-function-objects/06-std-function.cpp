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

int main() {
    [[maybe_unused]] std::function<bool(int, int)> cmp1 = CloserTo();
    std::cout << sizeof(CloserTo) << " " << sizeof(cmp1) << "\n";

    [[maybe_unused]] std::function<bool(int, int)> cmp2 = BigFunctor();
    std::cout << sizeof(BigFunctor) << " " << sizeof(cmp1) << "\n";

    int x = 10;
    [[maybe_unused]] std::function<bool(int, int)> cmp3 = [&](int a, int b) {
        return a + x < b + x;
    };
    std::cout << sizeof(cmp3) << "\n";
    
    // Type Erasure (need basic templates): https://www.youtube.com/watch?v=tbUCHifyT24
}
