#include <functional>
#include <iostream>
#include <vector>

struct Base {
    int x = 10;

    std::function<void()> print = [&]() { std::cout << "x = " << x << "\n"; };
    // std::function<void()> pretty_print = ....;
    // std::function<void()> read = ....;
};

struct Derived : Base {
    int y = 20;

    Derived() {
        print = [&]() { std::cout << "x = " << x << ", y = " << y << "\n"; };
    }
};

int main() {
    Base b;
    Derived d;
    b.print();
    d.print();

    Base &db = d;
    db.print();

    std::cout << sizeof(Base) << ", " << sizeof(Derived) << "\n";
}
