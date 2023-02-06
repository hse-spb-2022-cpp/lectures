#include <iostream>

struct err1 {};
struct err2 {};

struct with_destructor {
    int key;
    with_destructor(int key_) : key(key_) {}
    ~with_destructor() {
        std::cerr << "Destructed " << key << "\n";
    }
};

void bar() {
    with_destructor wd31(31);  // Implementation-defined stack unwind.
    try {
        with_destructor wd40(40);
        std::cerr << "3\n";
        throw err1();
        std::cerr << "x3\n";
    } catch (const err1 &e) {
        std::cerr << "4\n";
        throw err2();
        std::cerr << "x4\n";
    }
    std::cerr << "bar end\n";
}

void foo() {
    with_destructor wd20(20);  // Implementation-defined stack unwind.
    try {
        with_destructor wd30(30);  // Implementation-defined stack unwind.
        std::cerr << "2\n";
        bar();
        std::cerr << "x2\n";
    } catch (const err1 &e) {
        std::cerr << "z\n";
    }
    std::cerr << "foo end\n";
}

int main() {
    std::cerr << "1\n";
    {
        with_destructor wd10(10);
    }
    try {
        foo();
    } catch (...) {
        std::cerr << "caught!\n";
    }
    std::cerr << "main end\n";
}
