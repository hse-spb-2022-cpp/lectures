#include <iostream>

#ifdef DEBUG
#define debug_only
#else
#define debug_only if (false)
#endif

int main() {
    std::cout << "1\n";
    debug_only {
        std::cout << "2\n";
        std::cout << "3\n";
    }
    std::cout << "4\n";
}
