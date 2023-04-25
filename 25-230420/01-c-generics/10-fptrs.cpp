#include <iostream>

void apply(void (*operation)(int)) { // cdecl.org
    std::cout << "calling with 10\n";
    operation(10);
    (*operation)(10);  // the same.
}

using ApplyArgument = void(*)(int);
void apply2(ApplyArgument operation) { // cdecl.org
    std::cout << "calling with 10\n";
    operation(10);
}

void print_twice(int x) {
    std::cout << x << ", " << x << "\n";
}

template<typename T>
void print(T x) {
    std::cout << x << "\n";
}

int main() {
   apply(&print_twice);
   apply(print_twice);
   apply2(&print_twice);
   apply2(print_twice);

   // Doing the same:
   apply(&print<int>);
   apply(&print);  // Automatically: T=int.
   apply(print);

   apply([](int x) { std::cout << "lambda: " << x << "\n"; });  // lambdas with no captures can be converted
}
