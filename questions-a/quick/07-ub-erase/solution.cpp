#include <map>
#include <iostream>

int main() {
    std::map<int, int> m{
        {1, 100},
        {2, 101},
        {3, 102},
    };
    for (auto it = m.begin(); it != m.end();) {
        if (it->first % 2 == 0) {
            it = m.erase(it);
        } else {
            ++it;
        }
    }
    std::cout << m.size() << "\n";
}
