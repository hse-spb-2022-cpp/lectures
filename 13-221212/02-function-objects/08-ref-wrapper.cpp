#include <algorithm>
#include <cassert>
#include <functional>
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
        Counter c;
        Counter c2 = c;  // copy
        std::reference_wrapper<Counter> cwrap = c;  // copyable reference to c OR raw pointers with operator()
        assert(&cwrap.get() == &c);
        auto cwrap2 = cwrap;  // reference to c
        auto cwrap3 = std::ref(c);  // std::reference_wrapper<Counter>
        auto cwrap4 = cwrap3;

        c(1);  // 10 1
        c(2);  // 11 2
        c2(3);  // 10 3
        c2(4);  // 11 4
        c2(5);  // 12 5
        // std::reference_wrapper implements operator() only in addition to get()
        cwrap(6);  // 12 6
        cwrap(7);  // 13 7
        cwrap2(8);  // 14 8
        cwrap2(9);  // 15 9
        cwrap3(10);  // 16 10
        cwrap3(11);  // 17 11
        cwrap4(12);  // 18 12
        cwrap4(13);  // 19 13

        // Also: std::reference_wrapper<const Counter> and std::cref
    }
    std::cout << "=====\n";
    {
        std::vector<int> v{1, 2, 3, 4};
        Counter c;
        std::for_each(v.begin(), v.end(), std::ref(c));
        std::cout << "c.index = " << c.index << "\n";  // Should be 14
    }
}
