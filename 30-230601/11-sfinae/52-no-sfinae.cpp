#include <fstream>
#include <iostream>
#include <utility>
#include <type_traits>

template<typename T>
struct wrapper {
    T data;

    template<typename Arg>
    wrapper(Arg &&arg) : data(std::forward<Arg>(arg)) {}
};

int main() {
    [[maybe_unused]] std::ofstream f1("a.out");
    [[maybe_unused]] wrapper<std::ofstream> f2("b.out");

    [[maybe_unused]] int i1 = 10;
    [[maybe_unused]] wrapper<int> i2 = 20;

    // [[maybe_unused]] std::string s1 = 100;
    // [[maybe_unused]] wrapper<std::string> s2 = 200;

    static_assert(!std::is_constructible_v<std::string, int>);
    static_assert(!std::is_constructible_v<wrapper<std::string>, int>);  // oops
}
