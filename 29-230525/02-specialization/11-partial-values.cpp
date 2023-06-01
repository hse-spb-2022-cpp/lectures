#include <iostream>
#include <type_traits>

template<bool B, typename T, typename F>
struct conditional {
    using type = T;
};

template<typename T, typename F>
struct conditional<false, T, F> {
    using type = F;
};

int main() {
    conditional<2 * 2 == 4, int, double>::type x = 10.5;
    conditional<2 * 2 == 5, int, double>::type y = 10.5;
    std::cout << x << "\n";
    std::cout << y << "\n";
}
