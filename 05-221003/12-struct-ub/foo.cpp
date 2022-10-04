#include <vector>
#include <iostream>

struct Foo {
    int a = 10;
    std::vector<int> v;

    void method();
};

Foo get_foo() {
    return Foo{};
}

void Foo::method() {
    std::cout << "method() called " << a << "\n";
}
