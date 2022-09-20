#include <iostream>
#include <vector>

int main() {
    // Before C++11: > > because it looks too much like bitwise shift.
    std::vector<std::vector<int>> v(5, std::vector<int>(3, 123));
    // Similar to Python's `v = [[123] * 3] * 5`, but better.

    v[1].resize(10);
    for (std::size_t i = 0; i < v.size(); i++) {
        for (std::size_t j = 0; j < v[i].size(); j++) {
            if (j > 0) {
                std::cout << ' ';
            }
            std::cout << v[i][j];  // not v[i, j]
        }
        std::cout << '\n';
    }

    std::cout << "=====\n";
    for (const auto &row : v) {  // no copies! copy allocates memory, which is slow
        for (std::size_t j = 0; j < row.size(); j++) {
            if (j > 0) {
                std::cout << ' ';
            }
            std::cout << row[j];
        }
        std::cout << '\n';
    }
}
