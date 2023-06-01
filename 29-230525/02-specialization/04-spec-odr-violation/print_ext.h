#ifndef PRINT_EXT_H_
#define PRINT_EXT_H_

#include "print.h"

template<>
void print(const int &value) {
    std::cout << "mwahaha " << value << "\n";
}

#endif  // PRINT_EXT_H_
