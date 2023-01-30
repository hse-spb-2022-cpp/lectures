#include <iostream>
#include <vector>
int main() {
    std::vector<int> v(10);
    v??(0??) = 10;  // v[0] = 10;
    std::cout << v[0] << "\n";

    // You can ignore newline characters anywhere (including in a comment, phase 2) by \
       This line is a comment as well! \
       And this too!

    std::cout << "1\n";
    // Does the following line compiles??/
    std::cout << "2\n";
    std::cout << "3\n";
}
