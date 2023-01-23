#include <iostream>

template<typename F, typename T>
struct Caller {
    F operation;
    T value;

    void operator()() {
        operation(value);
    }
};

struct Printer {
    void operator()(int a) const {
        std::cout << a << "\n";
    }
};

int main() {
    Caller<Printer, int> c{Printer{}, 10};
    c();
    c();
}
