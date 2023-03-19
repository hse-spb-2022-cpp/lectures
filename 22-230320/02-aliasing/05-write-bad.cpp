#include <cstddef>
#include <iostream>

int main() {
    char xc[] = {10, 11, 12, 13};
    static_assert(sizeof(int) == 4);

    int *xptr = reinterpret_cast<int*>(xc);
    std::cout << std::hex << *xptr /* UB */ << "\n";
    // T1 == int, T2 == char. Нельзя.
}
