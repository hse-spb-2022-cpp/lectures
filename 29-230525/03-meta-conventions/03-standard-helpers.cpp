#include <type_traits>
#include <vector>

// https://en.cppreference.com/w/cpp/meta

// std::is_same
template<typename, typename> struct is_same : std::false_type {};
template<typename T>         struct is_same<T, T> : std::true_type {};

// More complicated, but still implementable
static_assert(std::is_integral_v<int>);
static_assert(!std::is_integral_v<double>);

struct F {
    void operator()(int) {}
    void operator()(std::vector<int>) {}
};
static_assert(std::is_invocable_v<F, int>);
static_assert(std::is_invocable_v<F, std::vector<int>>);
static_assert(!std::is_invocable_v<F, std::vector<short>>);

// is_convertible_v<From, To>: implicit conversion
// To foo() { return /* From{} */ }  // does not need default constructor
static_assert(std::is_convertible_v<int, double>);
static_assert(!std::is_convertible_v<int, double&>);
static_assert(std::is_convertible_v<int&, double>);
static_assert(!std::is_convertible_v<int, std::vector<int>>);

// explicit or implicit construction
static_assert(std::is_constructible_v<std::vector<int>>);
static_assert(std::is_default_constructible_v<std::vector<int>>);
static_assert(std::is_constructible_v<std::vector<int>, int>);
static_assert(std::is_constructible_v<std::vector<int>, int, int>);
static_assert(!std::is_constructible_v<std::vector<int>, int, int, int>);

static_assert(std::is_nothrow_constructible_v<std::vector<int>>);
static_assert(!std::is_nothrow_constructible_v<std::vector<int>, int>);

// Requires compiler support
struct Foo {};
struct Bar { virtual ~Bar(); };
static_assert(!std::is_polymorphic_v<Foo>);
static_assert(std::is_polymorphic_v<Bar>);

int main() {}
