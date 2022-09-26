#include <iostream>

struct Point {
    int x, y;
};

int main() {
    // aggregate initialization
    // Works with "aggregates", no details from me, changes between standards.
    // "Simple class": public members.
    [[maybe_unused]] Point p1{};
    [[maybe_unused]] Point p2{3};  // num = 3, warning about missing 'denom' initializer
    [[maybe_unused]] Point p3{3, 4};  // num = 3, denom = 4

    // Can disassemble some "simple classes" (not aggregates) as well.
    auto [x, y] = p3;
    std::cout << x << " " << y << "\n";
}
