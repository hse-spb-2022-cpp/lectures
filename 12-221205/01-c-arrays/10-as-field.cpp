#include <array>
#include <cassert>
#include <iterator>
#include <iostream>

const int MAX_N = 10;
struct Points {
    int n;
    int xs[MAX_N];  // Same as if 10 fields are defined.
    int ys[MAX_N];
};

int main() {
    Points a, b;
    std::cout << sizeof(a) << " " << sizeof(int) * (1 + 2 * MAX_N) << "\n";
    assert(sizeof(a) >= sizeof(int) * (1 + 2 * MAX_N));
    a.n = 1;
    a.xs[0] = 10;
    a.ys[0] = 20;
    
    b = a;  // Can reassign structs with arrays inside.
    assert(b.n == 1);
    assert(b.xs[0] == 10);
    assert(b.ys[0] == 20);
}
