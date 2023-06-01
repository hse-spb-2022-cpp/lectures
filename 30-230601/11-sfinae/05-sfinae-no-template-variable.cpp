#include <iostream>

struct BotvaHolder {
    static constexpr int botva = 10;
};

template<int> struct Foo {};

template<typename T>
void foo(T, Foo<T::botva>) {  // SFINAE is enabled
    std::cout << "1\n";
}

template<typename T>
void foo(T, std::nullptr_t) {
    std::cout << "2\n";
}

int main() {
    foo(BotvaHolder(), Foo<10>{});  // 1
    foo(BotvaHolder(), nullptr);  // 2
    foo(10, nullptr); // 2
    // foo(10, Foo{});  // CE
    // foo(BotvaHolder(), Foo<11>{});  // CE
}
