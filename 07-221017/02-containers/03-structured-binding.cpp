#include <algorithm>
#include <iostream>

int main() {
    std::pair<int, float> p = {10, 20.5};

    {
        auto [x, y] = p;
        std::cout << x << " " << y << "\n";
        x++;
        std::cout << x << " " << y << "\n";
        std::cout << p.first << " " << p.second << "\n";
    }
    std::cout << "=====\n";
    {
        auto &[x, y] = p;
        std::cout << x << " " << y << "\n";
        x++;
        std::cout << x << " " << y << "\n";
        std::cout << p.first << " " << p.second << "\n";
    }
    // warning!
    {
        std::pair<int, int> p = std::minmax(30, 20);
        std::cout << p.first << " " << p.second << "\n";  // Ok!
    }
    {
        auto [x, y] = std::minmax(30, 20);
        std::cout << x << " " << y << "\n";  // UB
    }
}
