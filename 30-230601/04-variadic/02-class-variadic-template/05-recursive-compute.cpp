#include <boost/core/demangle.hpp>
#include <iostream>
#include <string>

template<std::size_t I, typename ...Ts>
struct type_getter {};

template<typename T, typename ...Ts>
struct type_getter<0, T, Ts...> {
    using type = T;
};

template<std::size_t I, typename T, typename ...Ts>
struct type_getter<I, T, Ts...> {
    using type = typename type_getter<I - 1, Ts...>::type;
};

int main() {
    [[maybe_unused]] typename type_getter<0, int, std::string>::type x = 10;
    [[maybe_unused]] typename type_getter<1, int, std::string>::type y = "hello";
}
