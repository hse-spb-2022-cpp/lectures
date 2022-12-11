#include <algorithm>
#include <iostream>
#include <vector>

struct Counter {
    int index = 10;
    void operator()(int value) {
        std::cout << index << " " << value << "\n";
        index++;
    }
};

int main() {
    {
        std::vector<int> v{1, 2, 3, 4};
        Counter c;
        std::for_each(v.begin(), v.end(), c);
        std::cout << "c.index = " << c.index << "\n";  // May be 10
    }
    {
        std::vector<int> v{1, 2, 3, 4};
        Counter c;
        c = std::for_each(v.begin(), v.end(), c);
        std::cout << "c.index = " << c.index << "\n";  // Should be 14
    }
}
