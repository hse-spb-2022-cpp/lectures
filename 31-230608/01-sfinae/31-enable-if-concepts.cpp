#include <cassert>
#include <type_traits>

struct A { int val = 0; };
struct B { int val = 0; };
struct C { int val = 0; };
struct D { int val = 0; };
struct Foo { int val = 0; };

template<typename T>
constexpr bool good_for_plus = std::is_same_v<A, T> ||
                               std::is_same_v<B, T> ||
                               std::is_same_v<C, T> ||
                               std::is_same_v<D, T>;

template<typename T, typename U>
int operator+(const T &a, const U &b) requires good_for_plus<T> && good_for_plus<U> {
    return a.val + b.val;
}

int main() {
    A a{10};
    C c{30};
    [[maybe_unused]] Foo foo{50};
    assert(a + c == 40);
    // assert(a + foo == 60);
    // assert(foo + foo == 60);
}
