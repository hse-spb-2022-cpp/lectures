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

    for (std::pair<int, double> p : m) {
        std::cout << p.first << " --> " << p.second << "\n";
        p.first += 100;  // WTF?
    }
    std::cout << "\n";

    for (auto [key, value] : m) {
        std::cout << key << " --> " << value << "\n";
        // key += 100;  // key is const
        value += 100;  // does not affect map
    }
    std::cout << "\n";

    for (auto &[key, value] : m) {
        // key *= 2;
        value *= 2;
    }
    std::cout << "\n";

    for (const auto &[key, value] : m) {
        std::cout << key << " --> " << value << "\n";
        // value *= 2;
    }
    std::cout << "\n";
}
