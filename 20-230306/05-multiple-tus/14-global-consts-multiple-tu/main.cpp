#include <iostream>
#include "a.h"

int main() {
    std::cout << "From main()\n";
    std::cout << str1 << " " << &str1 << "\n";
    std::cout << str2 << " " << &str2 << "\n";
    std::cout << str3 << " " << &str3 << "\n";
    std::cout << str4 << " " << &str4 << "\n";
    std::cout << Foo::str1 << " " << &Foo::str1 << "\n";
    std::cout << Foo::str2 << " " << &Foo::str2 << "\n";
    std::cout << Foo::str3 << " " << &Foo::str3 << "\n";
    std::cout << Foo::str4 << " " << &Foo::str4 << "\n";

    foo();
}
