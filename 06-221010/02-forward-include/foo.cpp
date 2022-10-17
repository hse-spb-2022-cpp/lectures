#include "foo.hpp"
#include "bar.hpp"

void Foo::doit() {
    bs.push_back(Bar());
    bs.resize(10);
    Bar b2;
    // b2.bar_do();
}

void foo_friend() {
    Bar b3;
}
