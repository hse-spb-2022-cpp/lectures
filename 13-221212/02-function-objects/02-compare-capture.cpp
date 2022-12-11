#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

struct CloserTo {
    int center;

    bool operator()(int a, int b) const {
        return std::abs(a - center) < std::abs(b - center);
    }
};

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    sort(v.begin(), v.end(), CloserTo{3});
    for (int x : v) {
        std::cout << x << "\n";
    }
}
