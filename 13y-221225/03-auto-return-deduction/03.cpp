#include <iostream>
#include <boost/core/demangle.hpp>

auto foo(bool x) {
    return x ? 0.0f : 0LL;  // meh :(
}

int main() {
    std::cout << boost::core::demangle(typeid(foo(false)).name()) << "\n";
}
