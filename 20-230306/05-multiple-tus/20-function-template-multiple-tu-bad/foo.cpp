#include "print.hpp"
#include <iostream>

namespace {
struct my_secret_type {};
std::ostream &operator<<(std::ostream &os, const my_secret_type &) {
    return os << "secret";
}
}

void foo() {
    print(2);
    print(2.3);
    print(my_secret_type());
}
