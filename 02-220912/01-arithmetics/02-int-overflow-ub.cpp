#include <iostream>

int main() {
    int i = 1;
    while (true) {
        i = i * 3;  // UB is typically caught by -fsanitize=undefined, execution
                    // continues
        std::cout << i << "\n";
        if (i < 0) {  // Typically optimized out by the compiler.
            std::cout << "Overflow detected\n";
            return 0;
        }
    }
}
