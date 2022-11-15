#include <algorithm>
#include <iostream>

int main() {
    const auto &val = std::min(3, 4);
    std::cout << val << "\n";

    const auto &[min1, max1] = std::minmax(3, 4);
    std::cout << min1 << " " << max1 << "\n";

    // pair<const int &, const int &>
    auto [min2, max2] = std::minmax(3, 4);
    std::cout << min2 << " " << max2 << "\n";
}
