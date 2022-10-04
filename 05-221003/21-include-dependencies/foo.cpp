#include <iostream>
#include "foo.hpp"

Foo get_foo() {
    return Foo{};
}

void Foo::method() {
    std::cout << "method() called " << a << "\n";
}

void Foo::method_unused() {
    std::cout << "method_unused() called " << a << "\n";
}
