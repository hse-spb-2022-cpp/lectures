#include <algorithm>
#include <iostream>

int main() {
    int data[] = {1, 2, 3, 4, 5};
    std::cout << std::size(data) << "\n";

    int *dptr = data;  // array-to-pointer decay, implicit
    std::cout << &data[0] << " " << &data << " " << dptr << "\n";  // All the same
    std::cout << data[0] << " " << *dptr << "\n";  // 1
    std::cout << data[2] << " " << *(dptr + 2) << "\n";  // 3
    dptr += 2;
    std::cout << data[1] << " " << *(dptr - 1) << "\n";  // 2
    std::cout << data[1] << " " << *(dptr + (-1)) << "\n";  // 2
    std::cout << data[1] << " " << dptr[-1] << "\n";  // 2
    std::cout << data[1] << " " << (-1)[dptr] << "\n";  // 2

    std::sort(std::begin(data), std::end(data));
    std::sort(&data[0], &data[4] + 1);
    std::sort(data, data + 5);

    // std::cout << *(dptr - 3) << "\n";  // UB, out of bounds
    // std::cout << *(dptr + 3) << "\n";  // UB, out of bounds
}
