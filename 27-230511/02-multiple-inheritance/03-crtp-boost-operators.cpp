#include <iostream>
#include <boost/operators.hpp>

// Potential problems: lots of empty bases, size bloat.
// See "Empty Base Optimization": https://en.cppreference.com/w/cpp/language/ebo
// See tricks from Boost: https://www.boost.org/doc/libs/1_78_0/libs/utility/doc/html/utility/utilities/operators.html#utility.utilities.operators.usage.base_class_chaining_and_object_s
struct point
    : private boost::addable<point, point>
    , private boost::subtractable<point, point>
{
    int x = 0, y = 0;

    point() {}
    point(int x, int y) : x(x), y(y) {}

    point operator+=(const point &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    point operator-=(const point &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
};

int main() {
    point a(1, 2), b(3, 10);
    point c = a + b;
    std::cout << c.x << " " << c.y << "\n";
    std::cout << sizeof(point) << "\n";  // My modern compiler: still 8 bytes, not 12 (EBO).
}
