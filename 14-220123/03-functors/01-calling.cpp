#include <iostream>

template<typename F>
void apply(F operation) {
    std::cout << "Calling with 10\n";
    operation(10);
}

struct Print {
    void operator()(int x) const {
        std::cout << x << "\n";
    }
};

struct PrintTwice {
    void operator()(int x) const {
        std::cout << x << ", " << x << "\n";
    }
};

void no_op(int) {}
// void no_op(double) {}

int main() {
    apply/*<void(*)int>*/(no_op);
    apply/*<Print>*/(Print{});
    apply/*<Print>*/(Print{});
    apply/*<PrintTwice>*/(PrintTwice{});
    // apply(12);
}
