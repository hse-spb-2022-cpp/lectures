#include <iostream>

struct Point {
    int x, y;

    int dist2() {
        return x * x + y * y;
    }

    void operator+=(Point other) {
        x += other.x;
        y += other.y;
    }
};

void foo(const Point &p) {
    // WTF, use static_cast, it won't compile. Don't use const_cast, it compiles.
    Point &p2 = (Point&)p;
    // Point &p3 = static_cast<Point&>(p);
    std::cout << p2.dist2() << "\n";

    p2 += Point{5, 5};
    std::cout << "after modification: " << p.x << " " << p.y << "\n";
}

int main() {
    Point p;
    p.x = 10;
    p.y = 20;
    foo(p);  // OK

    const Point const_p{30, 40};
    foo(const_p);  // UB when calling dist2()
}
