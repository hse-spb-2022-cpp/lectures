#include <iostream>

void for_each(int *begin, int *end, void (*f)(int)) {
    while (begin != end)
        f(*begin++);
}

void print_int(int x) {
    std::cout << x << "\n";
}

int main(void) {
    int arr[10]{};
    arr[3] = 100;
    arr[5] = 200;
    for_each(arr, arr + 10, print_int);
}
