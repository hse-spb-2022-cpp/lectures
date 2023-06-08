#include <type_traits>
#include <vector>

template<typename T>
void foo(T &a, const T &b) noexcept(std::is_nothrow_copy_assignable_v<T>) {
    a = b;
}

template<typename T>
void bar(T &a, const T &b) noexcept(noexcept(a = b)) {
    a = b;
}

// We can write complex expressions: noexcept(std::is_nothrow_copy_assignable_v<T> && 2 * 2 == 4)
// In C++20 there is a similar construct: `requires requires { ..... }`

int main() {
    int a = 10, b = 20;
    static_assert(noexcept(foo(a, b)));
    static_assert(noexcept(bar(a, b)));

    std::vector<int> v1, v2;
    static_assert(!noexcept(foo(v1, v2)));
    static_assert(!noexcept(bar(v1, v2)));
}
