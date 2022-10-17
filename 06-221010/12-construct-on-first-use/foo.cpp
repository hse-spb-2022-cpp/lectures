#include <iostream>
#include "foo.hpp"

Foo::Foo() {
    std::cout << "Foo()\n";
}

Foo &get_foo() {  // construct-on-first-use
    static Foo f;  // like global variable, but initialized at first execution of this line
    return f;
}
