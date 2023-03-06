#include <iostream>
#include <string>

extern int var_main;  // can be written in a header

int var1 = 10;
std::string var2 = "hello" + std::to_string(var_main);

namespace {  // multiple definition otherwise
int var2_len = var2.size();
}

void foo() {
    std::cout << "From foo()\n";
    std::cout << var1 << " " << &var1 << "\n";
    std::cout << var2 << " " << &var2 << "\n";
    std::cout << var2_len << "\n";
}
