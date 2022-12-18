#include <iostream>
#include <map>

int main() {
    std::map<int, int> m{
        {1, 1000},
        {2, 1000},
        {3, 1000},
    };

    int x;
    std::cin >> x;
    m.erase(x);

    m[2]++;
    std::cout << m[2] << "\n";  // 1001 or 1
}
