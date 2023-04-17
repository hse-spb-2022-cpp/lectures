#include <iostream>

using arr45 = int[4][5];

// All the same:
// void foo(int arr[3][4][5]) {
// void foo(int arr[][4][5]) {
// void foo(int (*arr)[4][5]) {  // What if: (*arr) --> *arr
void foo(arr45 *arr) {
    std::cout << arr[1][2][3] << "\n";
    // static_cast<int*>(arr) + 1 * (4 * 5) + 2 * 5 + 3
}

template<std::size_t N, std::size_t M, std::size_t K>
void foo2(int (&arr)[N][M][K]) {
    std::cout << arr[1][2][3] << "\n";
    std::cout << N << " " << M << " " << K << "\n";
}

int main() {
    int arr[3][4][5]{};
    std::cout << sizeof(arr) << "\n";
    // Consecutive elements.
    std::cout << &arr[0][0][0] << "\n";
    std::cout << &arr[0][0][1] << "\n";
    std::cout << &arr[0][0][2] << "\n";
    std::cout << &arr[0][0][3] << "\n";
    std::cout << &arr[0][0][4] << "\n";
    std::cout << &arr[0][1][0] << "\n";
    std::cout << &arr[0][1][1] << "\n";
    arr[1][2][3] = 123;
    // arr[1, 2, 3] = 123;  // Not like in Pascal, see operator,
    foo(arr);
    foo2(arr);
}
