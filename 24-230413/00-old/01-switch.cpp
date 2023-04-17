#include <iostream>
#include <string>

int main() {
    for (int x = 1; x <= 5; x++) {
        std::cout << "x=" << x << "\n";

        switch (x) {  // May be a jump table, a binary search, a series of if-else...
            case 1:
            case 10:
                std::cout << "  1 or 10\n";
                [[fallthrough]];
            case 2 + 2:  // Only consts, but 2+2 is ok
                std::cout << "  4\n";
                [[fallthrough]];
            case 2:  // Although sorting `case`s alphabetically or by their semantics is more popular
                std::cout << "  2\n";
                break;
            default:  // Although it's usually the last
                std::cout << "  default\n";
                [[fallthrough]];
            case 3:
                std::cout << "  3\n";
                break;  // No warning in GCC, but it's better to write: what if we add another `case`?        }
        }
    }
    /*
    std::string s;
    switch (s) {  // Compilation Error :( Integers only.
    }
    */

    // I've never seen in the wild, but it's fun: https://en.wikipedia.org/wiki/Duff%27s_device
}
