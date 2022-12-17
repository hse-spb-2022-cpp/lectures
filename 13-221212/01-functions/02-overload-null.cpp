#include <cstdlib>
#include <iostream>

struct node {};

void foo(int) {
    std::cout << "foo(int)\n";
}

void foo(node*) {
    std::cout << "foo(node*)\n";
}

int main() {
    [[maybe_unused]] node *x = 0;
    foo(0);
    foo(NULL);
    foo(nullptr);  // C++11
}
