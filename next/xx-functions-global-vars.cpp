#include <iostream>

int a = 10, b = 20;

void print_a() {  // returns `void` (has no values), i.e. returns nothing
    std::cout << a << "\n";
}

void print(int x) {  // takes a single parameter: `x`
    std::cout << x << "\n";
}

int sum(int a, int b) {  // returns `int`, takes two parameters: `a` and `b`, just like local variables
    return a + b;  // should always return, otherwise UB
}

int main() {
    print_a();  // 10
    print(5);  // 5
    print(a + b);  // 30
    print(sum(a, b));  // 30
}
