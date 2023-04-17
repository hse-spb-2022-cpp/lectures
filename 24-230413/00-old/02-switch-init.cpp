#include <iostream>

int main() {
    for (int x = 1; x <= 5; x++) {
        std::cout << "x=" << x << "\n";

        switch (x) {
            case 1:
                std::cout << "  1\n";
                break;
            case 4:
                std::cout << "  4\n";
                break;
            case 2: {
                [[maybe_unused]] int wtf0 = 0;
                std::cout << "  2\n";
            } break;
            default: /* { */
                [[maybe_unused]] int wtf1 = 0;  // Compilation Error in C++
                                                // May be left uninitialized in C
                std::string s;  // Even worse Compilation Error: one has to remember
                                // whether to call desturctor. Nah.
                std::cout << "  default\n";
                /* } */ break;
            case 3:
                [[maybe_unused]] int wtf2 = 0;  // No `case` below, so no "crosses initialization" errors.
                std::cout << "  3\n";
                break;
        }
    }
}
