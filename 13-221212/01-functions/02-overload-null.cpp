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
    foo(0);
    foo(NULL);
    foo(nullptr);  // C++11
}
