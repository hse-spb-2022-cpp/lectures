#include <iostream>

void print() {
}

template<typename T>
void print(const T &v) {
    std::cout << v;
}

template<typename T1, typename T2>
void print(const T1 &v1, const T2 &v2) {
    std::cout << v1 << " " << v2;
}

template<typename T1, typename T2, typename T3>
void print(const T1 &v1, const T2 &v2, const T3 &v3) {
    std::cout << v1 << " " << v2 << " " << v3;
}

// "Variadic template" is a template which has a "template parameter pack"
// https://en.cppreference.com/w/cpp/language/parameter_pack
// It is NOT a "variadic function" (C-style `printf`-like): https://en.cppreference.com/w/c/variadic

template<typename /* template parameter pack */ ...Ts>
// Mnemonics: ... on the left of declared pack.
void println(const Ts &...vs) {  // "function parameter pack"
    // Mnemonics: ... on the right of the used pack.
    // No way to "index" an element because they may have different types.
    // No simple way to force all elements to have the same type.
    print(vs...);  // pack expansion
    // print(10, 20, 'x')
    std::cout << " - " << sizeof...(vs) << " element(s)\n";
}

int main() {
    println(10, 20, 'x');
    println(10);
    println<int, double>(10, 20);  // explicit template arguments
}
