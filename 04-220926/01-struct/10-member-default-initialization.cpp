#include <iostream>

struct ratio {
    int num = 0;  // C++11: member default initialization
    int denom = 1;
};

int main() {
    ratio r;
    std::cout << r.num << "\n";
    std::cout << r.denom << "\n";
    std::cout << ratio{}.num << "\n";

    ratio r2{3, 4};
    std::cout << r2.num << " " << r2.denom << "\n";
}
