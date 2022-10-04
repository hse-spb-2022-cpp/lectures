#include <iostream>
#include <vector>

// Should have definition. Method are supposedly defined outside of the struct.
struct Foo {
    int a = 10;
    std::vector<int> v;

    void method() {
        std::cout << "method() called " << a << "\n";
    }
};

Foo get_foo();

int main() {
    get_foo().method();

    Foo f = get_foo();
    f.method();
}
