#include <cassert>
#include <cstddef>

// Convention since C++98: a "function" from a type/value to types/values/functions.
// Not like Rust traits, probably not "типаж".

// Similar to std::iterator_traits
template<typename T>
struct iterator_traits {  // General case (may be absent)
    using value_type = typename T::value_type;
    using difference_type = typename T::difference_type;

    // Not in std::iterator_traits, useless
    static constexpr int modern_magic = 3;  // Modern, can also be `const`
    enum { old_magic = 3 }; // For older buggy compilers: https://stackoverflow.com/a/205000/767632
};

template<typename T>
struct iterator_traits<T*> {  // Corner case, can be specialized
    using value_type = T;
    using difference_type = std::ptrdiff_t;
};

template<typename It>
void foo(It begin, It end) {
    [[maybe_unused]] typename iterator_traits<It>::difference_type n = end - begin;
    [[maybe_unused]] typename iterator_traits<It>::value_type first = *begin;
    // Since C++11: `auto` is very helpful
}

template<typename It>
struct my_iterator_wrapper {
    typename iterator_traits<It>::value_type v;  // No `auto` fields yet.
};

int main() {
}
