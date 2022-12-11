#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>

bool compare_gt(int a, int b) {
    return a > b;
}

int main() {
    std::set<int, bool(*)(int, int)> v({1, 2, 3, 4, 5, 6, 7, 8}, compare_gt);
    for (int x : v) {
        std::cout << x << "\n";
    }
}
