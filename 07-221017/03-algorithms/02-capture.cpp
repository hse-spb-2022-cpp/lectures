//#define _GLIBCXX_DEBUG  // For stdlibc++
//#define _LIBCPP_DEBUG  // For libc++
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    std::vector v{1, 30, 2, 10, 3, 20, 4, 5};
    std::sort(v.begin() + 2, v.end() - 1);

    for (int x : v) std::cout << " " << x;
    std::cout << "\n";

    int middle = 7;

    std::sort(v.begin(), v.end(), [&](int a, int b) {
        return std::abs(a - middle) < std::abs(b - middle);
    });

    for (int x : v) std::cout << " " << x;
    std::cout << "\n";
}
