#include <iostream>
#include <vector>

struct Foo {
    int x;
    std::vector<int> y;
};

int main() {
    [[maybe_unused]] int x;  // Automatic storage duration.
                             // "На стэке".
    std::cout << "x created\n";

    Foo f;

    for (int x = 0; x < 10; x++) {  // shadowing (-Wshadow); independent x
        [[maybe_unused]] std::vector<int> v(10);
        if (v[2] == 123) {
            break;
        }
        if (v[3] == 456) {
            return 0;
        }
    }
    // old 'x' is available again

    [[maybe_unused]] int data[100];
    // [[maybe_unused]] int data2[100'000'000];  // stack overflow
    // data2[50'000'000] = 123;
}
