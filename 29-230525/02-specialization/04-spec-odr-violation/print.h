#ifndef PRINT_H_
#define PRINT_H_

#include <iostream>

template<typename T>
void print(const T &value) {
    std::cout << value << "\n";
}

#endif  // PRINT_H_
