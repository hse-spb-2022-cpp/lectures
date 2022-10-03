#include <iostream>
#include <vector>

// https://en.cppreference.com/w/cpp/language/type
struct Bar;  // forward declaration

struct Foo {
    std::vector<Bar> bs;

    void doit();  // declaration
    friend void foo_friend();  // declaration
};

struct Bar {
    Foo f;
};

void Foo::doit() {  // definition: `Foo::` is important
    bs.push_back(Bar());
    Bar b2;
    bs[0].bar_do();
}

void foo_friend() {  // definition: `Foo::` for friends is not needed
    Bar b3;
}

int main() {
    // TODO: two friends of different classes?
}
