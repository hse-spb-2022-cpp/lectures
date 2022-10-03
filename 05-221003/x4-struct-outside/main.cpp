#include <vector>
#include <iostream>

// Should have definition. Method are supposedly defined outside of the struct.
struct Foo {
    int a = 10;  // Should be exactly 10, IFNDR otherwise.
    std::vector<int> v;

    void method();
    void method_unused();
};

Foo get_foo();

int main() {
    get_foo().method();

    Foo f = get_foo();
    f.method();

    Foo f2;
    f2.method();
}
