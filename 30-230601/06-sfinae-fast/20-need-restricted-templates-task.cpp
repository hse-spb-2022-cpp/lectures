#include <cassert>
#include <iostream>
#include <string>
#include <vector>

struct A { int val = 0; };
struct B { int val = 0; };
struct C { int val = 0; };
struct D { int val = 0; };

template<typename T, typename U>
int operator+(const T &a, const U &b) {  // alternative: 16 overloads
    return a.val + b.val;
}

struct E { int val2 = 0; };
struct F { int val2 = 0; };

// FIXME: issue 1: not possible to use multiple times
#if 1
template<typename T, typename U>
int operator+(const T &a, const U &b) {
    return a.val2 + b.val2;
}
#endif

int main() {
    A a{10};
    C c{30};
    assert(a + c == 40);  // should work

    std::string s = "hello";
    std::vector<int> vec{1, 2, 3};
    s = s + "world";  // should work
    s = s + vec;  // FIXME: issue 2: confusing error: `string` has no member called `val`

    [[maybe_unused]] E e{40};
    [[maybe_unused]] F f{50};
    assert(e + f == 90);  // FIXME: does not compile
}
