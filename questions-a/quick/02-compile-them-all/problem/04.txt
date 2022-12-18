#include "a.hpp"

namespace {
int x = 500;
}

int Foo::get() {
    return b.x + x;
}
