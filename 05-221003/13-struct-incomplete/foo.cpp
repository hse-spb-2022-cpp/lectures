#include <vector>
#include <iostream>

struct Foo {
    int a = 10;
    std::vector<int> v;

    void method();
};

Foo& get_foo() {
    static Foo f;
    return f;
}

void call_method(Foo &f) {
    f.method();
}

void Foo::method() {
    std::cout << "method() called " << a << "\n";
}
