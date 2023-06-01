#include <iostream>
#include <tuple>

template<typename ...As, typename ...Bs>
void foo(As ...as, Bs ...bs) {
    std::cout << "foo(" << sizeof...(as) << ", " << sizeof...(bs) << ")\n";
}

template<typename ...As, typename ...Bs>
void bar([[maybe_unused]] std::tuple<As...> at, Bs ...bs) {
    std::cout << "bar(" << sizeof...(As) << ", " << sizeof...(bs) << ")\n";
}

template<typename ...As, typename ...Bs>
void baz([[maybe_unused]] std::tuple<int, As...> at, int, Bs ...bs) {
    std::cout << "baz(" << sizeof...(As) << ", " << sizeof...(bs) << ")\n";
}

template<typename ...As, typename ...Bs>
void baz_bad([[maybe_unused]] std::tuple<As..., int> at, Bs... bs, int) {
    std::cout << "baz(" << sizeof...(As) << ", " << sizeof...(bs) << ")\n";
}

int main() {
    // GCC, Clang: 0, 3
    // Visual Studio (and standard?): compilation error
    foo(1, 2, 3);

    // Compilation error: where to put the argument: As or Bs?
    // foo<int>(1);

    // 2, 2
    bar(std::tuple{1, 2}, 3, 4);

    // Parameter pack should be the last one for successful deduction.
    baz(std::tuple{1, 2}, 3, 4);  // 1, 1
    // baz_bad(std::tuple{1, 2}, 3, 4);  // Neither As nor Bs are deduced, compilation error.
    // baz_bad<int>(std::tuple{1, 2}, 3);  // I don't know whether this should work or not.
}
