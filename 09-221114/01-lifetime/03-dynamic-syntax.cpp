#include <iostream>

struct Foo {
    Foo() {
        std::cout << "Foo()\n";
    }
    Foo(int x) {
        std::cout << "Foo(" << x << ")\n";
    }
};

int main() {
    // dynamic storage duration
    {
        Foo *f = new Foo;  // Foo f; // default initialization
        delete f;
    }
    {
        Foo *f = new Foo();  // default initialization
        delete f;
    }
    {
        Foo *f = new Foo{};  // default initialization
        delete f;
    }
    {
        Foo *f = new Foo(10);  // direct initialization
        delete f;
    }
    {
        Foo *f = new Foo{10};  // direct list initialization
        delete f;
    }
    {
        Foo *f_arr = new Foo[5];
        delete[] f_arr;
        // delete f_arr;  // UB
    }
    {
        Foo *f_arr = new Foo[5]{1, 2, 3};  // copy initialization + value initialization
        delete[] f_arr;
    }
}
