#include <iostream>
#include "foo.hpp"

Foo::Foo() {
    std::cout << "Foo()\n";
}

Foo f;

Foo &get_foo() {
    return f;
}
