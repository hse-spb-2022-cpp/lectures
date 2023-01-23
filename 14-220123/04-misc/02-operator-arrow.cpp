#include <iostream>

struct point {
    int x = 0, y = 0;
};

struct point_wrapper {
    point p;
    point &operator*() {
        return p;
    }

    point *operator->() {
        return &p;
    }
};

int main() {
    point_wrapper p;
    std::cout << (*p).x << "\n";
    std::cout << (*p).y << "\n";
    std::cout << p->x << "\n";  // (p.operator->())->x
}
