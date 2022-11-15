#include <iostream>

int id_val(int x) {
    return x;
}

const int &id_ref(const int &x) {
    return x;
}

int main() {
    // Rvalue lifetime disaster, Arno Schoedl.
    {
        const int &x = id_val(10);
        std::cout << x << "\n";
    }
    {
        const int &x = id_ref(10);
        std::cout << x << "\n";
    }
}
