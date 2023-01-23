#include <iostream>

// class template
template<typename/* class */ T, char default_value>
struct templ_foo {
    T value;
    bool exists;
};

int main() {
    [[maybe_unused]] templ_foo<int, 10> x;
    [[maybe_unused]] templ_foo<int, 10> y;
    [[maybe_unused]] templ_foo<int, 11> z;
    x = y;  // OK
    x = z;  // CE: different types

    struct Foo {};
    struct Bar {};
    Foo x1;
    Bar y1;
    x1 = y1;
}
