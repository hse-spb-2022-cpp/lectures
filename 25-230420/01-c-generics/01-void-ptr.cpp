#include <iostream>
#include <vector>

int main() {
    int a = 10;
    char b = 'X';
    std::vector<int> v{1, 2, 3};

    [[maybe_unused]] void *p0 = nullptr;
    void *p1 = &a;  // implicit conversion: void* points to any object
    void *p2 = &b;
    void *p3 = &v;

    std::cout << p2 << "\n";
    // *p2;  // compilation error
    std::cout << *static_cast<int*>(p1) << "\n";
    std::cout << *static_cast<char*>(p2) << "\n";
    std::cout << static_cast<std::vector<int>*>(p3)->size() << "\n";

    // static_cast<short*>(p1);  // OK
    // *static_cast<short*>(p1);  // UB, strict aliasing violation, like reinterpret_cast<short*>(&a).

    // Impossible to know where does void* point.
}
