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
    int city_position;
    std::cin >> city_position;

    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    sort(v.begin(), v.end(), CloserTo{city_position});
    sort(v.begin(), v.end(), [=](int a, int b) {  // Can also be: [&], [city_position]
        return std::abs(a - city_position) < std::abs(b - city_position);
    });
    for (int x : v) {
        std::cout << x << "\n";
    }
}
