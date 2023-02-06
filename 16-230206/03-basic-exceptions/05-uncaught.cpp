#include <iostream>

struct err1 {};
struct err2 {};

struct with_destructor {
    int key;
    with_destructor(int key_) : key(key_) {}
    ~with_destructor() {
        std::cout << "Destructed " << key << "\n";
    }
};

void bar() {
    with_destructor wd31(31);  // Implementation-defined stack unwind.
    try {
        with_destructor wd40(40);
        std::cout << "3\n";
        throw err1();
        std::cout << "x3\n";
    } catch (const err1 &e) {
        std::cout << "4\n";
        throw err2();
        std::cout << "x4\n";
    }
    std::cout << "bar end\n";
}

void foo() {
    with_destructor wd20(20);  // Implementation-defined stack unwind.
    try {
        with_destructor wd30(30);  // Implementation-defined stack unwind.
        std::cout << "2\n";
        bar();
        std::cout << "x2\n";
    } catch (const err1 &e) {
        std::cout << "z\n";
    }
    std::cout << "foo end\n";
}

int main() {
    std::cout << "1\n";
    {
        with_destructor wd10(10);
    }
    try {
        foo();
    } catch (...) {
        throw;
    }
    std::cout << "main end\n";
}
