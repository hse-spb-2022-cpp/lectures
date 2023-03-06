#ifndef PRINT_HPP_
#define PRINT_HPP_

#include <iostream>

template<typename T> void print(const T &value);  // Optional.

// Can be in a separate print_impl.hpp to decrease visual clutter.
//
// General implementation of print<> should always be in the header,
// so it can be implicitly instantiated on demand. Otherwise: undefined reference.
// See https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
template<typename T> void print(const T &value) {
    std::cout << value << "\n";
}

#endif  // PRINT_HPP_
