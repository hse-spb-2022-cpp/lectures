#include <algorithm>

int main() {
    {
        auto [x, y] = std::minmax(10, 20);
        std::cout << x << "\n";  // UB
    }
    {
        auto p = std::minmax(10, 20);
        std::cout << p.first << "\n";  // UB, because pair<const int&, const int&>
    }
    {
        const std::pair<const int &, const int&> p = std::minmax(10, 20);
        std::cout << p.first << "\n";  // Still UB
    }
    {
        auto x = std::minmax(10, 20).first;
        std::cout << x << "\n";  // Not UB, because auto ~ int
    }
    {
        int a = 10, b = 20;
        auto [x, y] = std::minmax(a, b);
        std::cout << x << "\n";  // OK: reference to either a or b
    }
}
