#include <iostream>


const int var1 = 10;
const std::string var2 = "hello" + std::to_string(var1);

void foo();

int main() {
    std::cout << "From main()\n";
    std::cout << var1 << " " << &var1 << "\n";
    std::cout << var2 << " " << &var2 << "\n";
    foo();
}
