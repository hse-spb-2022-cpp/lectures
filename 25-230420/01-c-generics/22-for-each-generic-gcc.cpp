#include <cstddef>
#include <iostream>

void for_each(void *begin, void *end, std::size_t elem_size, void (*f)(const void*)) {
    for (; begin != end; begin += elem_size) {
        f(begin);  // Can only pass element by pointer
    }
}

void print_int(const int *x) {
    std::cout << *x << "\n";
}

int main(void) {
    int arr[10]{};
    arr[3] = 100;
    arr[5] = 200;
    for_each(arr, arr + 10, sizeof(arr[0]),
        print_int  // Needs -fpermissive and pile of luck
    );
}
