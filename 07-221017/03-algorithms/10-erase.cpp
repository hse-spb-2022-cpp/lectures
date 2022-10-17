#include <set>
#include <iostream>

int main() {
    {
        std::set<int> s{3, 1, 2, 4, 2};//, 100, 101, 102, 103, 104, 105, 106, 107};
        for (int x : s) {
            if (x % 2 == 0) {
                s.erase(x);
                // UB при переходе к следующему элементу
            }
        }
        std::cout << s.size() << "\n";
    }
}
