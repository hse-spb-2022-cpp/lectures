#include <map>
#include <iostream>

int main() {
    std::map<int, int> m{
        {1, 100},
        {2, 101},
        {3, 102},
    };
    for (auto [key, value] : m) {
        if (key % 2 == 0) {
            m.erase(key);
        }
    }
    std::cout << m.size() << "\n";
}
