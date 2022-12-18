#include <iostream>
#include <map>

int main() {
    std::map<int, int> m{
        {1, 1000},
        {2, 1000},
        {3, 1000},
    };
    auto it = m.find(2);

    int x;
    std::cin >> x;
    m.erase(x);

    it->second++;
    std::cout << m[2] << "\n";  // 1001 or 1
}
