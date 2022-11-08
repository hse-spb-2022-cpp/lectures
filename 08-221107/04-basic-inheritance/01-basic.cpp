#include <iostream>

struct Base {  // Базовый класс (base) в C++. Родительский/предок/надкласс/суперкласс (Python, Java).
    int x = 10;
    void foo() const {
        std::cout << "x=" << x << "\n";
    }

private:
    int very_secret = 20;  // for this class and its friends only

protected:
    int secret = 30;  // for this class and its derived classes
    // Please use 'private' still.
};

struct Derived : Base {  // Производный класс (derived). Дочерний/подкласс.
    // Base base;  // better alternative: композиция (composition)
    int y = 40;
    void bar() const {
        foo();
        std::cout << "x=" << x << ", y=" << y << ", secret=" << secret << "\n";
        // int z = very_secret;
    }
};

int main() {
    {
        Derived d;
        std::cout << "d.x=" << d.x << ", d.y=" << d.y << "\n";
        d.x = 123;
        d.foo();
        d.bar();
        // int x = d.very_secret;
        // int y = d.secret;
    }
    std::cout << sizeof(Base) << "," << sizeof(Derived) << "\n";
}
