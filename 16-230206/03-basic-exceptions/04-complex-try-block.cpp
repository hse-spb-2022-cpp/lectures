#include <iostream>

struct err1 {};
struct err2 {};

void bar() {
    try {
        try {
            std::cout << "3\n";
            throw err1();
            std::cout << "x3\n";
        } catch (const err1 &e) {
            std::cout << "4\n";
            throw err2();
            std::cout << "x4\n";
        } catch (const err2 &e) {
            std::cout << "x5\n";
        }
    } catch (int e) {
        std::cout << "caught int???\n";
//    } catch (const err2 &e) {
//        std::cout << "caught err2!\n";
//        throw e;
    }
    std::cout << "bar end\n";
}

void foo() {
    try {
        try {
            std::cout << "2\n";
            bar();  // std::cout << "3\n4\n"; throw err2();
            std::cout << "x2\n";
        } catch (const err1 &e) {
            std::cout << "z\n";
        }
        std::cout << "x21\n";
    } catch (int e) {
        std::cout << "x22\n";
    }
    std::cout << "foo end\n";
}

int main() {
    try {
        std::cout << "1\n";
        foo();
        std::cout << "xxx\n";
    } catch (const err2 &) {
        std::cout << "5\n";
    }
    std::cout << "main continues\n";
}
