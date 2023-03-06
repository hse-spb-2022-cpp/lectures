#include <iostream>
#include <functional>

struct Applier {
    int value;

    // We only know how to write it inside the class, no ODR violations here surprisingly.
    template<typename F>
    void apply(F operation) {
        std::cout << "Calling with " << value << "\n";
        operation(value);
    }
};

struct Print {
    void operator()(int x) {
        std::cout << x << "\n";
    }
};

int main() {
    Applier a{10};
    Print p;
    a.apply(p);
}
