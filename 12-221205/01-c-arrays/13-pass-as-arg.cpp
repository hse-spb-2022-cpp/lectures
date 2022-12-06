#include <array>
#include <iostream>
#include <iterator>
#include <cstddef>

// void foo(int arr[]) {  // Actually void foo(int *arr)
// void foo(int arr[5]) {  // Actually void foo(int *arr)
void foo(int arr[15]) {  // Actually void foo(int *arr)
// void foo(int *arr) {
    // Careful: sizeof pointer
    std::cout << "arr[0] = " << arr[0] << ", sizeof = " << sizeof(arr) << "\n";
}

void foo_good(int arr[], int arr_len) {
    std::cout << "arr[0] = " << arr[0] << ", len = " << arr_len << "\n";
    // foo_good(arr, sizeof arr / sizeof arr[0]);  // bad as well
    foo_good(arr, arr_len);  // ok
}

int main() {
    int arr[10]{1, 2, 3};
    foo(arr);
    foo_good(arr, sizeof arr / sizeof arr[0]);  // C style.
    // 2-dimensional arrays are out of scope
}
