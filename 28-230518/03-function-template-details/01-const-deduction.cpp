#include <iostream>

template<typename T>
void print(/* const */ T &a) {
    a++;  // Assume `a` is non-const (which actually may be false).
    std::cout << a << std::endl;
}

template<typename T>
void print_off(T a) {
    a++;
    std::cout << a << std::endl;
}

int main() {
    // auto &a = 10;
    // print(10);  // Arg=int. T=int. int &x;

    // auto b = 20;
    print_off(20);  // Arg=int. T=int. int x;

    const int x = 30;
    // auto &c = x;
    // print(x);  // Arg=const int. T=const int. const int &x; Compilation error inside.

    // auto d = x;
    print_off(x);  // Arg=const int. T=int. int x;
}
// More details: approx 15m of CppCon 2014: Scott Meyers: Type Deduction and Why You Care: https://www.youtube.com/watch?v=wQxj20X-tIU
