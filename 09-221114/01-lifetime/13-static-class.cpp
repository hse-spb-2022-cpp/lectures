#include <cassert>
#include <iostream>

struct Counter {
private:
    static int calls;  // Declaration

public:
    int calls_on_creation = calls;

    static int counter() {
        return ++calls;
    }
};

int Counter::calls = 10;

int main() {
    assert(Counter::counter() == 11);
    assert(Counter::counter() == 12);
    Counter c;
    std::cout << c.calls_on_creation << "\n";
    assert(Counter::counter() == 13);
    assert(Counter::counter() == 14);
    // std::cout << Counter::calls << "\n";
}
