#include <iostream>

struct err1 {};
struct err2 {};

void bar() {
    try {
        try {
            std::cerr << "3\n";
            throw err1();
            std::cerr << "x3\n";
        } catch (const err1 &e) {
            std::cerr << "4\n";
            throw err2();
            std::cerr << "x4\n";
        } catch (const err2 &e) {
            std::cerr << "x5\n";
        }
    } catch (int e) {
        std::cerr << "caught int???\n";
    } catch (const err2 &e) {
        std::cerr << "caught err2!\n";
        throw e;
    }
    std::cerr << "bar end\n";
}

void foo() {
    try {
        try {
            std::cerr << "2\n";
            bar();  // std::cerr << "3\n4\n"; throw err2();
            std::cerr << "x2\n";
        } catch (const err1 &e) {
            std::cerr << "z\n";
        }
        std::cerr << "x21\n";
    } catch (int e) {
        std::cerr << "x22\n";
    }
    std::cerr << "foo end\n";
}

int main() {
    try {
        std::cerr << "1\n";
        foo();
        std::cerr << "xxx\n";
    } catch (const err2 &) {
        std::cerr << "5\n";
    }
    std::cerr << "main continues\n";
}
