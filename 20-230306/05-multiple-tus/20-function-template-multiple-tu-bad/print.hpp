#ifndef PRINT_HPP_
#define PRINT_HPP_

#include <iostream>

// Rules for template argument names are (according to my experiments) similar to functions:
// 1. Names do not matter.
// 2. Default value can only be specified in either declaration or definition, not both.
// Rules for ODR are old as well: sequences of tokens of definitions in TUs should be the same.
template<typename T> void print(const T &value);  // Optional.

#endif  // PRINT_HPP_
