#include <cassert>
#include <set>
#include <iostream>

int main() {
    {
        std::set<int> s{3, 1, 2, 4, 2};
        std::cout << s.size() << "\n";
        for (int x : s) {
            std::cout << " " << x;
        }
        std::cout << "\n";

        // All operations are O(log)
        s.insert(10);
        s.erase(2);

        std::cout << s.count(3) << "\n";
        std::cout << s.count(33) << "\n";
        if (s.count(10)) { /* ... */ }
        if (s.count(10) != 0) { /* ... */ }
    }

    {
        std::multiset<int> ms{3, 1, 2, 4, 2};
        std::cout << ms.size() << "\n";
        for (int x : ms) {
            std::cout << " " << x;
        }
        std::cout << "\n";

        ms.insert(10);
        ms.erase(2);  // O(log) + count(2)

        std::cout << ms.count(3) << "\n";  // O(log) + count(3)
    }

    {
        const int N = 1'000'000;
        std::multiset<int> ms;
        for (int i = 0; i < N; i++) {
            ms.insert(10);
        }

        for (int STEP = 0; STEP < N; STEP++) {
            assert(ms.count(10) == N);
            assert(ms.count(11) == 0);
        }
    }
}
