#include <type_traits>

// Convention for traits "returning" a single type:
template<typename T> struct remove_const {  // std::remove_const
    using type = T;  // standard name, a convention
};
template<typename T> struct remove_const<const T> {
    using type = T;
};
// Since C++11: helper has a `_t` suffix
template<typename T> using remove_const_t = typename remove_const<T>::type;

void foo() {
    // Like a function call, but <> instead of () and both types/values as arguments.
    [[maybe_unused]] remove_const_t<const int> x = 10;
    x++;
}

// Convention for traits "returning" a single value
// See std::integral_constant https://en.cppreference.com/w/cpp/types/integral_constant
template<typename T> struct is_const : std::false_type {
    // No boilerplate here because of inheritance
};
template<typename T> struct is_const<const T> : std::true_type {
};

static_assert(is_const<const int>::value);
static_assert(!is_const<int>::value);

// Since C++17: alias template, another convention:
// Helper has a `_v` suffix
template<typename T>
inline constexpr bool is_const_v = is_const<T>::value;

static_assert(is_const_v<const int>);
static_assert(!is_const_v<int>);

int main() {}
