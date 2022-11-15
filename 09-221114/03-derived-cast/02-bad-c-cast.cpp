#include <iostream>
#include <string>

struct Base {
    int x = 10;
    void foo() const {
        std::cout << "x=" << x << "\n";
    }
};

struct Derived : Base {
    int y = 20;
    void bar() const {
        foo();
        std::cout << "y=" << y << "\n";
    }
};

void foo(const Base &b) {
    std::cout << "foo(" << b.x << ")\n";
    const Derived &d = static_cast<const Derived&>(b);
//    const std::string &d = static_cast<const std::string&>(b);  // UB, but does not compile
//    const std::string &d = (const std::string&)b;  // UB
    std::cout << ".s=" << d.s << "\n";
}

int main() {
    Derived d;
    foo(d);
}
