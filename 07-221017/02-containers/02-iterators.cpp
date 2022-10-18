#include <set>
#include <iostream>

int main() {
    std::multiset<int> ms{3, 1, 2, 4, 2};
    std::cout << ms.size() << "\n";

    typename std::multiset<int>::iterator it = ms.begin();
    // range-based for gets expanded into:
    [[maybe_unused]] auto it2 = ms.begin();
    //   1    2   2   3   4
    //   ^    ^   ^   ^   ^    ^
    // begin                  end
    for (; it != ms.end(); ++it) {  // ++it faster than it++
        std::cout << " " << *it;
    }
    std::cout << "\n";
    // All operations with iterators are O(1) amortized.

    ms.erase(ms.find(2));
    std::cout << ms.size() << "\n";
    ms.erase(ms.find(2));
    std::cout << ms.size() << "\n";

    // Элемента не существует: find() == end()
    // erase(end()) - UB
    ms.erase(ms.find(2));  // UB
    std::cout << ms.size() << "\n";

    std::multiset<int> ms2;
    std::cout << (ms.end() == ms2.end()) << "\n";  // not guaranteed, may be 0
}
