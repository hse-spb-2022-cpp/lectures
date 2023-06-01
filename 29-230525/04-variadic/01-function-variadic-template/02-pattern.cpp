#include <iostream>

void print(int a, int b, int c, int d) {
    std::cout << a << " " << b << " " << c << " " << d << "\n";
}

template<typename ...Ts>
void print_twice(const Ts &...vs) {
    print(239, vs..., 17, vs...);
}

template<typename ...Ts>
void print_plus_10(const Ts &...vs) {
    print((vs + 10)...);
    // print((1 + 10), (2 + 10), (3 + 10), (4 + 10))
}

template<typename ...Ts>
void print_double(const Ts &...vs) {
    print((vs + vs)...);  // expanded in parallel, should have the same length.
}

int times_three(int x) { return x * 3; }

template<typename ...Ts>
void print_double(const Ts &...vs) {
    print(times_three(vs)...);  // print(times_three(1), times_three(2), times_three(3), times_three(4))
    print(times_three(vs...));  // print(times_three(1, 2, 3, 4))
}

int main() {
    print_twice(1);
    print_plus_10(1, 2, 3, 4);
    print_double(1, 2, 3, 4);
}
