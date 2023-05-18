#include <iostream>
#include <type_traits>

// Since C++17
template<typename T>
const T default_value{};  // may be non-const as well.

int main() {
    // Alternative: default_value<int>()
    // Alternative: type_info<int>::default_value;
    [[maybe_unused]] auto x = default_value<int>;
    [[maybe_unused]] auto y = default_value<double>;

    // Useful in metaprogramming: function of types/compile consts.
    std::cout << std::is_trivially_copyable_v<int> << std::endl;
    // std::cout << std::is_trivially_copyable<int>::value << std::endl;
    std::cout << std::is_trivially_copyable_v<std::istream> << std::endl;
}
