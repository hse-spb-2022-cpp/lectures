#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

struct Greater {  // Functor (jargon)/special case of "functional object"
    bool operator()(int a, int b) const {
        return a > b;
    }

    int operator()(int a, int b, int c) const {  // overloads are possible
        return a + b + c;
    }
};

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    const Greater g;  // 'const' is optional, just to demonstrate const-qualifier
    assert(g.operator()(5, 4));
    assert(!g.operator()(4, 5));
    assert(g(5, 4));
    assert(!g(4, 5));
    assert(Greater().operator()(4, 5));
    assert(Greater()(4, 5));

    sort(v.begin(), v.end(), g /* Greater() */);
    for (int x : v) {
        std::cout << x << "\n";
    }
}
