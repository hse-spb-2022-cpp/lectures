#include <iostream>

struct Point {
    int x, y;

    int dist2() const {  // Add `const` everywhere when possible
        // x++;
        return x * x + y * y;
    }

    void operator+=(Point other) {
        x += other.x;
        y += other.y;
    }
};

void print(const Point &p) {
    std::cout << p.x << " " << p.y << "\n";
    std::cout << p.dist2() << "\n";
}

int main() {
    Point p;
    p.x = 10;
    p.y = 20;
    print(p);  // OK

    const Point const_p{30, 40};
    print(const_p);  // OK
}
