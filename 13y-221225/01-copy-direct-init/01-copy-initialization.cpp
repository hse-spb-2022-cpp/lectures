#include <string>

struct Foo {
    Foo(int x) {}
    explicit Foo(std::string s) {}
};

void do_something(Foo g) {
}

Foo create_something() {
    Foo h(5);
    return h;  // copy initialization 3/3
}

int main() {
    Foo f(10);
    Foo g = f;  // copy initialization 1/3
    do_something(g);  // copy initialization 2/3
}
