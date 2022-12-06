#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <iterator>

void print_all(int *beg, int *en) {
    // Just like iterators
    for (int *it = beg; it != en; it++) {
        std::cout << *it << "\n";
    }
}

int main() {
    int data[]{40, 20, 10, 30};

    int *one_past_end = data + 4;
    assert(one_past_end - data == 4);
    print_all(data, one_past_end);
    // int x = *one_past_end;  // dereference is UB.

    int *ub1 = data - 1;
    int *ub2 = data - 1 + 1;
    int *ub3 = data + 5;
    int *ub4 = data + 5 - 5;
}
