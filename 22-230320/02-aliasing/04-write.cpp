#include <cstddef>
#include <iostream>

int main() {
    int x = 123456;
    char *xc = reinterpret_cast<char*>(&x);
    static_assert(sizeof(int) == 4);

    xc[0] = 10;
    xc[1] = 11;
    xc[2] = 12;
    xc[3] = 13;
    std::cout << std::hex << x << "\n";
}
