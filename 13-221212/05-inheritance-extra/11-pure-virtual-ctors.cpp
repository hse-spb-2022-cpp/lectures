#include <iostream>

struct Base {
    int value = 123;

    virtual void printTo() = 0;

    Base() {
        printTo();
    }
};

/*void Base::printTo() {  // BUT WHY
    std::cout << "Not so pure, eh?\n";
}*/

struct Derived : Base {
    void printTo() override {
    }
};

int main() {
    // Base b;  // class is still abstract.
    Derived d;
}
