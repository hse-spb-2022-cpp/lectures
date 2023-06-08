#include <iostream>

// Two overloads
template<typename T>
auto sum1(const T &v) {
    return v;
}

template<typename T, typename ...Ts>
auto sum1(const T &v, const Ts &...vs) {
    // sum1(1, 2, 3) = 1 + sum1(2, 3)
    // sum1(2, 3) = 1 + sum1(3)
    // sum1(3) = other overload, 3.
    return v + sum1(vs...);
}

// Single overload, since C++17
template<typename T, typename ...Ts>
auto sum2(const T &v, const Ts &...vs) {
    // `if constexpr` does not compile the second branch.
    if constexpr (sizeof...(vs) == 0) {
        return v;
    } else {
        return v + sum2(vs...);  // No sum2().
    }
}

// Another alternative: wrap into a class and use template specializations.
template<typename Head, typename ...Tail>
struct Summator {
    auto operator()(const Head &h, const Tail &...tail) {
        return h + Summator<Tail...>{}(tail...);
    }
};
template<typename Head>
struct Summator<Head> {
    auto operator()(const Head &h) {
        return h;
    }
};

int main() {
    std::cout << sum1(1, 2, 3) << "\n";
    std::cout << sum2(1, 2, 3) << "\n";
    std::cout << Summator<int, int, int>{}(1, 2, 3) << "\n";
}
