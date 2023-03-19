#include <iostream>

int main() {
    float f = 1.0;
    static_assert(sizeof(float) == sizeof(int));

    int *x = reinterpret_cast<int*>(&f);
    std::cout << std::hex << *x /* UB */ << "\n";

    // Strict aliasing rule:
    // Можно через указатель p типа T1 обращаться к объекту типа T2 только если:
    // 1. T1 == T2 (но T1 может быть более const)
    // 2. T1 --- базовый класс T2
    // .....
    // 10. T1 == char, unsigned char, std::byte

    // Выше нарушаем: T1 == int, T2 == float.

    // Тут тоже нарушение с точки зрения C++: https://en.wikipedia.org/wiki/Fast_inverse_square_root
    // Но, возможно, не с точки зрения C.
}
