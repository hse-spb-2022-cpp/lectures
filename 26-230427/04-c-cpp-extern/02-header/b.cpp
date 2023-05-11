#include <cstdio>
#include <iostream>
#include <vector>
#include "a.h"
#include "b.h"

int foo(int x) {  // OK
    return x + 1;
}

struct Foo {
    Foo() {
        std::printf("Foo\n");
    }
    ~Foo() {
        std::printf("~Foo\n");
    }
} f;

int my_main() {
    std::vector<int> v;
    std::cout << foo() << "\n";
    std::cout << foo(100) << "\n";
    return 0;
}
