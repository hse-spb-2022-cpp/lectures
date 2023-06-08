#include <boost/core/demangle.hpp>
#include <iostream>

int main() {
    auto f = [](int n) {  // deduced int
        if (n > 1) {
           return 100;
        } else {
           return 200;
           // return 200.0;  // will fail deduction
        }
    };
    std::cout << boost::core::demangle(typeid(f(10)).name()) << "\n";

    auto g = [](int n) -> double {
        if (n > 1) {
           return 100;
        } else {
           return 200.0;
        }
        // return "foo";  // compilation error: cannot cast to double
    };
    std::cout << boost::core::demangle(typeid(g(10)).name()) << "\n";
}
