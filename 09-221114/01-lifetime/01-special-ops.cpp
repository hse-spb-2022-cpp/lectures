#include <iostream>
#include <vector>

// Rules:
// 1. Lifetime starts exactly once, with a constructor (ctor).
// 2. Lifetime ends at most once, with a destructor (dtor).
//    Note: if it's not called, we probably get a memory/resource leak.
// 3. Ibject's address cannot be changed.
struct Foo {
    int value;
    std::vector<int> vec{1, 2, 3, 4, 5};
    Foo(int value_) : value(value_) {
        std::cout << "Foo(" << value << ") " << this << "\n";
    }
    Foo(const Foo &other) : value(other.value) {
        std::cout << "Foo(" << value << ") " << this << " <-- " << &other << "\n";
    }
    ~Foo() {  // no need to implement, see "rule of zero"
        std::cout << "~Foo(" << value << ") " << this << "\n";
    }
};

void test(const Foo &f) {
    std::cout << "&f = " << &f << "\n";
}

void consume(Foo param) {
    std::cout << "param=" << param.value << "\n";
}

Foo create() {
    std::cout << "create started\n";
    Foo f(100);
    std::cout << "create returning\n";
    return f;
}

int main() {
    Foo a(10);
    Foo b(20);
    {
        Foo c(30);
        c = b;  // assignment operator (operator=), no new objects created
    }
    std::cout << "=====\n";
    {
        [[maybe_unused]] Foo f1 = a;  // copy constructor (Foo(const Foo&)), we did not modify it
        // [[maybe_unused]] Foo f2(a);  // copy constructor (Foo(const Foo&)), we did not modify it
    }
    std::cout << "=====\n";
    consume(a);  // copy constructor
    consume(Foo(Foo(Foo(30))));  // new object, but copies are typically optimized
    consume(40);  // new object
    std::cout << "=====\n";
    [[maybe_unused]] Foo f2 = create();  // named return value optimization (NRVO) is possible
    std::cout << "&f2 = " << &f2 << "\n";
    std::cout << "=====\n";
    test(a);  // reference binding, no new objects created
    std::cout << "=====\n";
}
