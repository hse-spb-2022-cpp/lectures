#include <iostream>

struct Point {
    int x, y;

    int dist2() {
        return x * x + y * y;
    }
};

int main() {
    // aggregate initialization
    // Works with "aggregates", no details from me, changes between standards.
    // "Simple class": public members.
    [[maybe_unused]] Point p1{};  // implicit init: x=0, y=0
    [[maybe_unused]] Point p2{3};  // x = 3, warning about missing 'y' initializer
    [[maybe_unused]] Point p3{3, 4};  // x = 3, y = 4
    std::cout << p1.x << " " << p1.y << "\n";

    // Can disassemble some "simple classes" (not aggregates) as well.
    // It is called "structured binding".
    auto [x, yyy] = p3;
    std::cout << x << " " << yyy << "\n";
}
