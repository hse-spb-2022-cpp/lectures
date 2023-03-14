#include <iostream>

int var_main = 123;

extern int var1;  // can be written in a header
extern std::string var2;  // can be written in a header

//namespace {  // multiple definition otherwise
int var2_len = var2.size();
//}

// extern int var1 = 10;  // multiple definition (defined because of initialization)
// extern std::string var2 = "hello";  // multiple definition (defined because of initialization)

void foo();

int main() {
    std::cout << "From main()\n";
    std::cout << var1 << " " << &var1 << "\n";
    std::cout << var2 << " " << &var2 << "\n";
    std::cout << var2_len << " " << &var2_len << "\n";
    foo();
}
