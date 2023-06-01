#include <iostream>

// Since C++17: https://en.cppreference.com/w/cpp/language/fold
// Fold expression should always be inside its own parenthesis.

template<typename ...Ts>
auto sum1(const Ts &...vs) {
    return (vs + ...);  // unary right fold: v0 + (v1 + (v2 + v3))
    // return (... + vs);  // unary left fold: ((v0 + v1) + v2) + v3
}

template<typename ...Ts>
auto sum2(const Ts &...vs) {
    return (vs + ... + 0);  // binary right fold: v0 + (v1 + (v2 + 0))
    // return (0 + ... + vs);  // binary left fold: ((0 + v0) + v1) + v2
}

template<typename ...Ts>
auto sum_twice(const Ts &...vs) {
    return ((2 * vs) + ... + 0);  // patterns are allowed
}

template<typename ...Ts>
void print(const Ts &...vs) {
    // binary left fold: (std::cout << v0) << v1
    (std::cout << ... << vs) << "\n";
    // (std::cout << vs << ...) << "\n";  // incorrect
    // (0 + vs + ...)  // incorrect too
    // std::cout << ... << vs << "\n";  // incorrect fold expression

    // std::cout << ... << (vs << "\n");  // `v0 << "\n"` is not a valid expression
    // std::cout << (v0 << "\n") << (v1 << "\n") << (v2 << "\n");
}

int main() {
    // std::cout << sum1() << "\n";  // compilation error
    std::cout << sum1(1, 2, 3) << "\n";
    std::cout << sum1("hello", " ", std::string("world")) << "\n";

    std::cout << sum2() << "\n";
    std::cout << sum2(1, 2, 3) << "\n";

    std::cout << sum_twice(1, 2, 3) << "\n";

    print(1, "hello");
}
