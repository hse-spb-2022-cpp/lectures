#include <iostream>

struct Point {
    // members
    int x, y;  // default initialization (e.g. nothing for `int`, empty `vector`)

    // member function
    int dist2() {
        return x * x + y * y;
    }

    void operator+=(Point other) {  // operator overload
        x += other.x;
        y += other.y;
        // z = 10;
    }
};

void foo([[maybe_unused]] Point p) {
}

int main() {
    Point p;
    // std::cout << p.x << " " << p.y << "\n";  // UB: not initialized
    p.x = 10;
    p.y = 20;
    std::cout << p.x << " " << p.y << "\n";
    std::cout << p.dist2() << "\n";

    p += {5, 5};
    // p.operator+=(Point{5, 5});
    std::cout << p.x << " " << p.y << "\n";
}
