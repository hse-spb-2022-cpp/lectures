#include <cstddef>
#include <iostream>
#include <tuple>
#include <utility>

template<typename ...Ts, std::size_t ...Is>
void print_helper(const std::tuple<Ts...> &t, std::index_sequence<Is...>) {
    bool first = true;
    auto f = [&](const auto &v) {
        if (first) {
            first = false;
        } else {
            std::cout << " ";
        }
        std::cout << v;
    };
    (f(std::get<Is>(t)), ...);
    // f(std::get<0>(t)), (f(std::get<1>(t)), f(std::get<2>(t)));
    std::cout << "\n";
}

template<typename ...Ts>
void print(const std::tuple<Ts...> &t) {
    // Step 1: what do we want.
    std::cout << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t) << "\n";
    // Problem: get<I> needs I to be a compile-time constant.

    // Step 2: provide a compile-time list of constants in a helper type tag.
    print_helper(t, std::index_sequence<0, 1, 2>{});

    // Step 3: generate the sequence (can be done recursively)
    print_helper(t, std::make_index_sequence<sizeof...(Ts)>{});

    // Step 4 in C++20:
    auto print_helper_lambda = [&]<std::size_t ...Is>(std::index_sequence<Is...>) {
        // ...
    };
    print_helper_lambda(std::make_index_sequence<sizeof...(Ts)>{});
}

int main() {
    std::tuple t{1, 2.3, "hello"};
    print(t);
}
