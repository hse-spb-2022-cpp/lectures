#include <iostream>

struct int_wrapper {
    int data = 10;
    int &operator*() {
        return data;
    }
};

int main() {
    int_wrapper x;
    std::cout << *x << "\n";
    ++*x;
    std::cout << *x << "\n";
}
