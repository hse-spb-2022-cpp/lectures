#include <cassert>
#include <iostream>
#include <string>
#include <vector>

struct A { int val = 0; };
struct B { int val = 0; };
struct C { int val = 0; };
struct D { int val = 0; };

template<typename T>
void println(const T &v) {
    std::cout << v.val << "\n";
}

struct E { int val2 = 0; };
struct F { int val2 = 0; };

// FIXME: issue 1: not possible to use multiple times
#if 0
template<typename T>
void println(const T &v) {
    std::cout << v.val2 << "\n";
}
#endif

int main() {
    A a{10};
    println(a);  // 10

    std::string s = "hello";
    println(s);  // FIXME: issue 2: confusing error: `string` has no member called `val`

    [[maybe_unused]] E e{40};
    println(e);  // FIXME: does not compile
}
