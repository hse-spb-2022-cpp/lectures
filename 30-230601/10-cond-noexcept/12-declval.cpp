#include <optional>
#include <stdexcept>
#include <utility>
#include <vector>

template<typename T>
constexpr bool is_nothrow_copy_assignable_1 = noexcept(T() = static_cast<const T&>(T()));

struct Foo {
    Foo() {}
    Foo &operator=(const Foo &) noexcept {
        return *this;
    }
};

static_assert(is_nothrow_copy_assignable_1<std::optional<int>>);
static_assert(!is_nothrow_copy_assignable_1<std::vector<int>>);
// static_assert(is_nothrow_copy_assignable_1<Foo>);  // static assertion failed: constructor is not noexcept
// static_assert(is_nothrow_copy_assignable_1<std::runtime_error>);  // compilation error: no default constructor
// static_assert(is_nothrow_copy_assignable_1<int>);  // compilation error: cannot assign to a temporary int

template<typename T>
constexpr bool is_nothrow_copy_assignable_2 = noexcept(std::declval<T&>() = std::declval<const T&>());

static_assert(is_nothrow_copy_assignable_2<std::optional<int>>);
static_assert(!is_nothrow_copy_assignable_2<std::vector<int>>);
static_assert(is_nothrow_copy_assignable_2<Foo>);  // ok
static_assert(is_nothrow_copy_assignable_2<int>);  // ok
static_assert(is_nothrow_copy_assignable_2<std::runtime_error>);  // ok

int main() {
    // [[maybe_unused]] int x = std::declval<int>();  // compilation error: std::declval<> is only used in unevaluated context
}
