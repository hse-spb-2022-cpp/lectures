#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector v{1, 1, 1, 2, 2, 4, 5};
    //            0  1  2  3  4  5  6  7
    //          begin                  end
    //            [                    )
    typename std::vector<int>::iterator it = std::upper_bound(v.begin(), v.end(), 2);
    // *it > 2, *(--it) <= 2
    std::cout << it - v.begin() << "\n";  // 5

    it = std::upper_bound(v.begin(), v.end(), 3);
    // *it > 3, *(--it) <= 3
    std::cout << it - v.begin() << "\n";  // 5

    it = std::upper_bound(v.begin(), v.end(), 10);
    // *it > 10, *(--it) <= 10
    std::cout << it - v.begin() << "\n";  // 7

    // Number of 2s
    std::cout << std::upper_bound(v.begin(), v.end(), 2) - std::lower_bound(v.begin(), v.end(), 2) << "\n";
}
