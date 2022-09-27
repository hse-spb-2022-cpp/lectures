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
    double x1 = r.operator double();
    double x2 = static_cast<double>(r);  // explicit conversion
    std::cout << x << "\n";
    std::cout << r << "\n";  // implicit conversion to double
}
