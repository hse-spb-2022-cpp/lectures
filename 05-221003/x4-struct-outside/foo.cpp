#include <vector>
#include <iostream>

struct Foo {
    int a = 10;
    std::vector<int> v;

    void method();
    void method_unused();
};

Foo get_foo() {
    return Foo{};
}

void Foo::method() {
    std::cout << "method() called " << a << "\n";
}

void Foo::method_unused() {
    std::cout << "method_unused() called " << a << "\n";
}
