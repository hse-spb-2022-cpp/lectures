#include <cassert>
#include <iterator>
#include <iostream>
#include <string>

int main() {
    [[maybe_unused]] int a1[10];  // 10 default-initialized ints: uninitialized
    [[maybe_unused]] std::string a2b[10];  // constructors are still called
    [[maybe_unused]] int a2[10] = {};  // value-initialize all elements: 0.
    [[maybe_unused]] int a3[10]{};  // same

    [[maybe_unused]] int a4[10] = {1, 2, 3};  // value-initialize all elements
                                              // except first three (copy-initialized)
    int a5[10]{1, 2, 3};  // same, copy-initialized
    assert(a5[0] == 1);
    assert(a5[1] == 2);
    assert(a5[2] == 3);
    assert(a5[3] == 0);
    assert(a5[4] == 0);

    [[maybe_unused]] int a6[10] = { 0 };  // 0, 0, 0, 0, ...
    [[maybe_unused]] int a7[10] = { 1 };  // 1, 0, 0, 0, ...
    [[maybe_unused]] int a8[] = {1, 2, 3};  // size == 3
}
