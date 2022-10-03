#include <iostream>

double get();  // UB: return type differs from get.cpp

// IFNDR: Ill Formed, No Diagnostic Required

int main() {
    std::cout << get() << "\n";
}
