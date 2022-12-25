#include <string>

struct Foo {
    Foo(int x) {}
    explicit Foo(std::string s) {}
};

int main() {
    Foo f(10);  // direct initialization
    f = Foo(10);  // direct initialization + operator=
    f = Foo{10};  // direct initialization + operator=
    f = Foo{"hello"};  // direct initialization + operator=
    Foo g("hello");  // direct initialization
}
