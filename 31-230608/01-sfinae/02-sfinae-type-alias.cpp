#include <iostream>

struct BotvaHolder {
    using botva = int;
};

template<typename T> using GetBotva = typename T::botva;

template<typename T>
void foo(T, GetBotva<T>) {  // GetBotva is an alias, substitution failure happens 'here'.
    std::cout << "1\n";
}

template<typename T>
void foo(T, std::nullptr_t) {
    std::cout << "2\n";
}

int main() {
    foo(BotvaHolder(), 10);  // 1
    foo(BotvaHolder(), nullptr);  // 2
    foo(10, nullptr); // 2
    // foo(10, 10);  // CE
}
