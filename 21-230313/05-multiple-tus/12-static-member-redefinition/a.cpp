#include <iostream>
#include <string>

struct Foo {
    static int value;
};
//int Foo::value = 10;

void foo() {
    std::cout << "From foo()\n";
    std::cout << Foo::value << " " << &Foo::value << "\n";
}
