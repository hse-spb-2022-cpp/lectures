#include <iostream>

void bar(int i);

void foo() {
    for (int i = 0; i < 5; i++) {
        std::cout << "i=" << i << "\n";
        bar(i);
    }
}
