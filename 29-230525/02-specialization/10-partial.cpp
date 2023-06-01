#include <iostream>

template<typename T>
struct is_reference {
    static inline const bool value = false;
};

template<typename T1>
struct is_reference<T1&> {  // (const U)& as well.
    static inline const bool value = true;
};

template<typename T>
static const bool is_reference_v = is_reference<T>::value;

int main() {
    std::cout << is_reference_v<int> << "\n";
    std::cout << is_reference_v<int&> << "\n";
    std::cout << is_reference_v<const int&> << "\n";
}
