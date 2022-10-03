#include <vector>
#include <iostream>

struct Foo {
    int a = 10;
    std::vector<int> v;

    void method() {  // Definition inside struct: not ODR-violation, if the same everywhere.
        std::cout << "method() called " << a << "\n";
    }
};

Foo get_foo() {
    return Foo{};
}
