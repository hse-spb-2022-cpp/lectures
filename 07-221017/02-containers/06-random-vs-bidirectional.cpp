#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main() {
    std::vector v{10, 20, 30};
    std::list l{10, 20, 30};

    auto vit = v.begin();
    vit += 2;  // random access iterator
    std::cout << *vit << "\n";
    std::cout << vit - v.begin() << "\n";  // 2

    auto lit = l.begin();
    // lit += 2;
    ++lit;  // bidirectional iterator
    --lit;
    ++lit;
    ++lit;
    std::cout << *lit << "\n";
    std::cout << *std::next(l.begin(), 2) << "\n";  // #include <iterator>
    std::cout << std::distance(l.begin(), lit) << "\n";  // linear time for non-random access
}
