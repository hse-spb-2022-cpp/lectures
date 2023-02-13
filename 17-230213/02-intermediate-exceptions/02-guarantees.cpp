#include <cassert>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

void do_something() {
    throw std::bad_alloc();  // Uncomment when running under Valgrind/ASan, it does not like not having enough memory and will close instead of bad_alloc.
    std::vector<int> vec(100'000'000'000);
    vec[vec.size() - 1] = 123;
}

// Гарантии исключений
// Exception safety

void no_guarantee() {
    std::cout << "2+2=";
    int *data = new int[10];
    do_something();
    delete[] data;
    std::cout << "4\n";
}

// Basic exception safety: no leaks, no UB
void basic_guarantee_1() {
    std::cout << "2+2=\n";
    std::vector<int> data(10);
    do_something();
    std::cout << "4\n";
}

void basic_guarantee_2() {
    std::cout << "2+2=4\n";
    std::vector<int> data(10);
    do_something();
}

// Strong exception safety (rollback semantics): nothing unchanged
void strong_guarantee() {
    std::vector<int> data(10);
    do_something();
    // What is "nothing"? Can we output?
    std::cout << "2+2=4\n";
}

void noexcept_guarantee() {
    assert(std::cout.exceptions() == std::ios_base::goodbit);
    std::cout << "2+2=4\n";
}

int main(int argc, char *argv[]) {
    assert(argc == 2);
    try {
        switch (std::stoi(argv[1])) {
        case 0: do_something(); break;
        case 1: no_guarantee(); break;
        case 2: basic_guarantee_1(); break;
        case 3: basic_guarantee_2(); break;
        case 4: strong_guarantee(); break;
        case 5: noexcept_guarantee(); break;
        }
    } catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }
}
