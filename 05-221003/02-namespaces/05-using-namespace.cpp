#include <iostream>

int x = 10;

namespace ns {
int x = 20;
void foo() {
    std::cout << "foo()\n";
}
}

int main() {
    std::cout << x << " " << ::x << " " << ns::x << "\n";
    // foo();
    {
        std::cout << x << " " << ::x << " " << ns::x << "\n";
        // foo();
        using namespace ns;
        std::cout << /*x << " " <<*/ ::x << " " << ns::x << "\n";  // x is ambiguous
        foo();
    }
    std::cout << x << " " << ::x << " " << ns::x << "\n";
    // foo();
}
