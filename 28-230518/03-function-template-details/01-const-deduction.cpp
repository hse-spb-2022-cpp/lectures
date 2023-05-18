#include <iostream>

template<typename T>  // T=int, T=const int, T=vector<int>, T=const vector<int>
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
    // print<const int>(10);  // T=const int, const int &

    // print(10);  // Arg=int. T=int. int &x;
    // auto &a = 10;  // `auto` has same rules for deduction as templates

    print_off(20);  // Arg=int. T=int. int x;
    [[maybe_unused]] auto b = 20;

    const int x = 30;
    // print(x);  // Arg=const int. T=const int. const int &x; Compilation error inside.
    [[maybe_unused]] auto &c = x;  // auto=const int

    [[maybe_unused]] auto d = x;  // auto=int
    print_off(x);  // Arg=const int. T=int. int x;
}
// More details: approx 15m of CppCon 2014: Scott Meyers: Type Deduction and Why You Care: https://www.youtube.com/watch?v=wQxj20X-tIU
