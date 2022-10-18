#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>

const int N = 1'000'000;

int main() {
    std::set<int> s;
    for (int i = 0; i < N; i++) {
        s.insert(i);
    }
    for (int step = 0; step < N; step++) {
        // assert(*std::lower_bound(s.begin(), s.end(), 10) == 10);  // O(n) for std::set :(
        assert(*s.lower_bound(10) == 10);  // O(log)
    }
    std::cout << "OK\n";
}
