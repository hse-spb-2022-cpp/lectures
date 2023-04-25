#include <cstddef>
#include <iostream>
#include <string>

template<typename T>
void cpp_for_each(T *begin, T *end, void (*f)(const T*)) {
    for (; begin != end; begin += 1) {
        f(begin);
    }
}

void for_each(const void *begin, const void *end, std::size_t elem_size, void (*f)(const void*)) {
    for (; begin != end; begin = static_cast<char*>(begin) + elem_size) {
        f(begin);  // Can only pass element by pointer, not by value
    }
}

void print_int(const void *x) {
    std::cout << *static_cast<const int*>(x) << "\n";
}

void print_string(const void *x) {
    std::cout << *static_cast<const std::string*>(x) << "\n";
}

int main(void) {
    int arr[10]{};
    arr[3] = 100;
    arr[5] = 200;
    for_each(arr, arr + 10, sizeof(arr[0]), print_int);

    std::string sarr[2] = {"hello", "world"};
    for_each(sarr, sarr + 2, sizeof(sarr[0]), print_string);

    // for_each(sarr, sarr + 2, sizeof(sarr[0]), print_int);  // UB
}
