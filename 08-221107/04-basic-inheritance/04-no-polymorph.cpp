#include <iostream>
#include <vector>

struct Base {
    int x = 10;

    void print() const {
        std::cout << "x = " << x << "\n";
    }
};

struct Derived : Base {
    int y = 20;

    void print() const {
        std::cout << "x = " << x << ", " << "y = " << y << "\n";
    }
};

void print(const Base &db) {
    db.print();
}

int main() {
    Base b;
    Derived d;
    b.print();
    d.print();

    print(d);

    std::cout << sizeof(Base) << ", " << sizeof(Derived) << "\n";
}
