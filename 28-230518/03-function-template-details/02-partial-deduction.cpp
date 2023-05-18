#include <boost/lexical_cast.hpp>
#include <iostream>

// Can also combine with default arguments.
template<typename To, typename From>
To my_static_cast(From x) {
    return static_cast<To>(x);
}

template<typename TA, typename TB>
void print_two(const TA &a, const TB &b) {
    std::cout << a << ' ' << b << std::endl;
}

int main() {
    // Prefix of arguments is explicit, everything else is either default or deduced.
    [[maybe_unused]] auto z = my_static_cast<int>(10.5);
    std::cout << boost::lexical_cast<int>("123") + 50 << std::endl;

    // All will call print_two<int, double>:
    print_two<int, double>(10, 23.5);
    print_two<int>(10, 23.5);
    print_two<double>(10, 23.5);  // TA=double, TB=double. const double &a = 10;
    print_two<>(10, 23.5);  // Rarely used in favor of the next line:
    print_two(10, 23.5);
    // No way to specify non-prefix.
}
