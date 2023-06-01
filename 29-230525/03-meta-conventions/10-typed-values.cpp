#include <type_traits>

#if 0
template<typename T, T N> struct bad_fac {};
template<typename T>      struct bad_fac<T, 0> {};  // compilation error
#endif

// Workaround: wrap (T, N) inside a single type integral_constant

template<typename /*N*/> struct fac {};  // Basic case, never called;
template<typename T, T N>
inline constexpr auto fac_v =
    fac<std::integral_constant<T, N>>::value;

template<typename T, T N> struct fac<std::integral_constant<T, N>>
    : std::integral_constant<T, N * fac_v<T, N - 1>> {};
template<typename T>      struct fac<std::integral_constant<T, 0>>
    : std::integral_constant<T, 1> {};
static_assert(fac_v<int, 5> == 120);
// static_assert(fac_v<int, 100> == 120);

int main() {}
