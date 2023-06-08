#include <iostream>

// Actually the same as 02-sfinae-type-alias.cpp and 03-sfinae-type-inside-struct.cpp
// Extra reading: https://www.cppstories.com/2022/sfinea-immediate-context/

struct BotvaHolder {
    static constexpr int botva = 10;
};

template<typename T>
constexpr int GetBotva = T::botva;  // hard compilation error

template<int> struct Foo {};

template<typename T>
void foo(T, Foo<GetBotva<T>>) {  // Compilation error: the substitution failure is inside GetBotva<T>
    std::cout << "1\n";
}

template<typename T>
void foo(T, std::nullptr_t) {
    std::cout << "2\n";
}

int main() {
    foo(BotvaHolder(), Foo<10>{});  // 1
    foo(BotvaHolder(), nullptr);  // 2
    foo(10, nullptr); // 2???
    // foo(10, Foo{});  // CE
}
