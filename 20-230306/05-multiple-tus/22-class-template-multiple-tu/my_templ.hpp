#ifndef MY_TEMPL_HPP_
#define MY_TEMPL_HPP_

#include <iostream>

// Rules for template argument names are (according to my experiments) similar to functions:
// 1. Names do not matter.
// 2. Default value can only be specified in either declaration or definition, not both.
// Rules for ODR are old as well: sequences of tokens of definitions in TUs should be the same.
template<typename T>
struct my_template;  // Optional.

template<typename T>
struct my_template {
    void foo();
    void bar() {}  // Can be defined inside the struct
};

template<typename T>
void my_template<T>::foo() {  // No need in 'inline' because of template
    std::cout << "foo " << typeid(T).name() << "\n";
}

// Out-of-scope: explicit instantiations for faster compilation: https://stackoverflow.com/a/59614755/767632
//               E.g. `std::string=std::basic_string<char>`

#endif  // MY_TEMPL_HPP_
