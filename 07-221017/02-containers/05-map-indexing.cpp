#include <map>
#include <iostream>

int main() {
    // ~ set<pair<const int, double>>
    std::map<int, double> m{
        std::pair<int, double>{10, 12.5},
        /*std::pair<int, double>*/{20, 2.5},
        /*std::pair<int, double>*/{30, 3},
    };
    m.insert(std::pair{25, 40.1});
    m.insert({35, 40.1});
    m.emplace(44, 1.1);

    for (auto &[key, value] : m) {
        // key *= 2;
        value *= 2;
    }

    std::cout << m[10] << "\n";  // 25
    m[10]++;
    std::cout << m[10] << "\n";  // 26
    m[123] = 566;  // Создаётся новый элемент
    std::cout << m[123] << "\n";  // 566
    std::cout << m[124] << "\n";  // 0

    m[125] += 577;  // 0 += 577
    std::cout << m[125] << "\n";  // 577

    std::cout << m.count(500) << "\n";  // 0
    if (m[500] == 0) { /* ... */ }
    std::cout << m.count(500) << "\n";  // 1

    const auto &const_m = m;
//    std::cout << const_m[123] << "\n";
    std::cout << (*const_m.find(123)).second << "\n";
    std::cout << const_m.find(123)->second << "\n";

    *const_m.find(843579875);  // UB, please compare with .end() first
    std::cout << (const_m.find(843579875) == const_m.end()) << "\n";  // not UB
}
