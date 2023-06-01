#include <cassert>
#include <type_traits>

struct A { int val = 0; };
struct B { int val = 0; };
struct C { int val = 0; };
struct D { int val = 0; };
struct Foo { int val = 0; };

template<typename T>
constexpr bool good_for_plus = std::is_same_v<A, T> || std::is_same_v<B, T> || std::is_same_v<C, T> || std::is_same_v<D, T>;

template<typename T, typename U, typename /* Dummy */ = std::enable_if_t<good_for_plus<T> && good_for_plus<U>>>
int operator+(const T &a, const U &b) {
    return a.val + b.val;
}

// Compilation error: redefinition. Default values is not a part of the signature.
template<typename T, typename U, typename /* Dummy */ = std::enable_if_t<good_for_plus<T> && std::is_integral_v<U>>>
int operator+(const T &a, const U &b) {
    return a.val + b;
}

int main() {
    A a{10};
    C c{30};
    [[maybe_unused]] Foo foo{50};
    assert(a + c == 40);  // should work
    assert(a + 20 == 30);  // should work
    // assert(a + foo == 60);  // does not compile: no match for 'operator+'
    // assert(foo + foo == 60);  // does not compile: no match for 'operator+'
}
