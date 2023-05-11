#include <boost/core/demangle.hpp>
#include <iostream>

union Foo {
    struct X {  // OK, a type
        int x1, x2;
    };

    struct Y {  // OK, a type and a field
        int y1, y2;
    } y;

    struct {  // OK, a field
        int z1, z2;
    } z;

    struct {
        int wtf1, wtf2;
    };
    // Anonymous/unnamed struct members: C11, not in C++
    // Supported in C++ by GCC, Clang, VS.
    // Do not confuse with `struct { ... } x`.
};

int main() {
    [[maybe_unused]] Foo f;
    [[maybe_unused]] Foo::X fx;
    [[maybe_unused]] Foo::Y fy;

    // f.x1 = 10;

    f.y.y1 = 10;
    f.y.y2 = 20;

    f.z.z1 = 10;
    f.z.z2 = 20;
    std::cout << typeid(f.z).name() << "\n";
    std::cout << boost::core::demangle(typeid(f.z).name()) << "\n";

    // Non-standard C++, standard C11
    f.wtf1 = 10;
    f.wtf2 = 20;
}
