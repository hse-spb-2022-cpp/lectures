#include <iostream>

int func(int *a, float *b) {
   *a = 10;
   *b = 123.45;
   return *a;  // --> return 10;
}

int main() {
    {
        int a = 15;
        float b = 456.78;
        int res = func(&a, &b);
        std::cout << "res=" << res << "\n";
        std::cout << "a=" << a << "\n";
        std::cout << "b=" << b << "\n";
    }
    {
        int a = 15;
        int res = func(&a, reinterpret_cast<float*>(&a));
        std::cout << "res=" << res << "\n";
        std::cout << "a=" << a << "\n";
    }
}
