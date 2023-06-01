#include <iostream>

struct BotvaHolder {
    using botva = int;
};

template<typename T>
struct GetBotva {
    using type = typename T::botva;  // hard compilation error
};

template<typename T>
void foo(T, typename GetBotva<T>::type) {  // Compilation error: the substitution failure is inside GetBotva<T>
    std::cout << "1\n";
}

template<typename T>
void foo(T, std::nullptr_t) {
    std::cout << "2\n";
}

int main() {
    foo(BotvaHolder(), 10);  // 1
    foo(BotvaHolder(), nullptr);  // 2
    foo(10, nullptr); // 2???
    // foo(10, 10);  // CE
}
