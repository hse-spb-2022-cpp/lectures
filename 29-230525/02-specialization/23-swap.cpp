#include <algorithm>
#include <iostream>

namespace my_secret {
struct Basic {};
}

namespace std {
// void swap(my_secret&, my_secret&) {  // UB, overload.
template<> void swap(my_secret::Basic&, my_secret::Basic&) {  // Not UB, specialization. UB since C++20.
    std::cout << "swap(Basic)\n";
}
};

namespace my_secret {
template<typename T>
struct Foo {};

// template<> swap(my_secret::Foo<T>&, my_secret::Foo<T>&);  // partial specialization :(

// Cannot specialize std::swap. Instead: add an ADL-found version.
template<typename T>
void swap(Foo<T> &, Foo<T> &) {
    std::cout << "swap(Foo<T>)\n";
}
};

int main() {
    {
        my_secret::Basic a, b;
        std::swap(a, b);  // OK swap.

        using std::swap;  // Required for the next line to compile.
        swap(a, b);  // OK swap
    }
    {
        my_secret::Foo<int> a, b;
        std::swap(a, b);  // Wrong swap.

        using std::swap;  // Optional for the next line to compile, but won't break it.
        swap(a, b);  // OK swap, ADL.
    }
    // Moral: `using std::swap; swap(a, b)` in generic code.
}
