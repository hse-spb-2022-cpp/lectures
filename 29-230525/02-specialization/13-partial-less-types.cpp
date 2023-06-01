#include <iostream>

template<typename T, typename U>
struct is_same {
    static inline const bool value = false;
};

template<typename T>
struct is_same<T, T> {
    static inline const bool value = true;
};

template<typename T, typename U>
static const bool is_same_v = is_same<T, U>::value;

int main() {
    std::cout << is_same_v<int, long long> << "\n";
    std::cout << is_same_v<int, signed> << "\n";
    std::cout << is_same_v<int, signed&> << "\n";
    std::cout << is_same_v<int, unsigned> << "\n";
}
