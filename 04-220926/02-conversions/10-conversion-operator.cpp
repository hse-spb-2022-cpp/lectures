#include <iostream>

struct ratio {
    int num;
    int denom;

    operator double() const {
        std::cout << "operator double()\n";
        return num * 1.0 / denom;
    }
};

int main() {
    ratio r{3, 4};
    std::cout << r.num << "\n";
    double x = r;  // implicit conversion
    std::cout << x << "\n";
    std::cout << r << "\n";

    ratio r2 = r;
    std::cout << r2.num << "\n";
}
