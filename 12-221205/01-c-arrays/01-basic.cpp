#include <cassert>
#include <iterator>
#include <iostream>

const int N = 5;

int main() {
    // "C-arrays", "plain arrays"
    [[maybe_unused]] int var1, arr[2 * N], var2;
    // 10 uninitialized ints one after another.
    // Automatic storage duration
    // Size should be a compile-time expression, strictly greater than 0
    arr[2] = 123;
    assert(arr[2] == 123);
    assert(std::size(arr) == 10);  // C++-style
    assert(sizeof(arr) == 10 * sizeof(int));  // C style
    assert(sizeof(arr) / sizeof(arr[0]) == 10);  // C style
    // std::cout << arr[10];  // UB
    
    // No push_back/pop_back/insert/operator==/copying/...
    // int arr2[2 * N] = arr;  // Just does not compile
    // int arr3[2 * N];
    // arr3 = arr;

    // range-based-for is ok, though
    for (int &x : arr) {
        x = 10;
    }
}
