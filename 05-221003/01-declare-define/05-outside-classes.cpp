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
    bs.resize(10);
    Bar b2;
    bs[0].bar_do();
}

// friend functions are usual global functions with special handling
// two classes cannot have the same friend function
void foo_friend() {  // definition: `Foo::` for friends is not needed
    Bar b3;
}

int main() {
}
