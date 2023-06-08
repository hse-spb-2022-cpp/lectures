#include <cassert>
#include <type_traits>

struct A { int val = 0; };
struct B { int val = 0; };
struct C { int val = 0; };
struct D { int val = 0; };

template<typename...>
using void_t = void;

// Similar to std::void_t

template<typename T, typename U, void_t<decltype(std::declval<T>().val + std::declval<U>().val)>* /* ptr */ = nullptr>
int operator+(const T &a, const U &b) {
    return a.val + b.val;
}

int main() {
    A a{10};
    C c{30};
    assert(a + c == 40);  // should work
    assert(a + "x" == 60);  // does not compile: no match for 'operator+'
}
