#include <cstdio>
#include <iostream>
#include <vector>

// Question: why we needed it for DLL?
extern "C" int foo(/* TODO: int &x? */);  // Disable name mangling, and link like C.

int foo(int x) {  // OK
    return x + 1;
}

namespace a {
#if 0
// Warning: same as foo(), but different set of arguments. It's ok in C, though
// (e.g. printf).
extern "C" int foo(int);
#endif
}  // namespace a

struct Foo {
    Foo() {
        std::printf("Foo\n");
    }
    ~Foo() {
        std::printf("~Foo\n");
    }
} f;

extern "C" int my_main() {
    std::vector<int> v;
    std::cout << foo() << "\n";
    std::cout << foo(100) << "\n";
    return 0;
}
