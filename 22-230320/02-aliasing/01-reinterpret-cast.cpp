#include <cstddef>
#include <iostream>

int main() {
    int x = 123456;
    char *xc = reinterpret_cast<char*>(&x);
    // Becomes the following:
    // char *xc = static_cast<char*>(static_cast<void*>(&x));
    for (std::size_t i = 0; i < sizeof(x); i++) {
        std::cout << static_cast<int>(xc[i]) << "\n";
    }
    // 64  -30  1  0
    // 64 226   1  0
    // 64 + 256*(226 + 256*(1 + 256*0))
}
