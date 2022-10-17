#include <iostream>
#include "foo.hpp"

int b0 = get_foo().x;

struct Bar {
    Bar(int x) {
        std::cout << "b0=" << b0 << "\n";
        std::cout << "Bar(" << x << ", foo.x=" << get_foo().x << ")\n";
    }
};

Bar b1(10 + b0);
Bar b2(20 + b0);
