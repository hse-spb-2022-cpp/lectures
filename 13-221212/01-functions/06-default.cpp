#include <iostream>
#include <vector>

// K _last_ parameters can be defaulted.
void foo(int x, int y = 10, int z = 20) {
    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y << "\n";
    std::cout << "z = " << z << "\n";
}

void bar(std::vector<int> vec = {1, 2, 3}) {
    vec.push_back(100);
    std::cout << "vec.size() = " << vec.size() << "\n";
}

int main() {
    foo(1);
    foo(2, 3);
    // foo(2, z=3);  // Python-only, not C++
    foo(4, 5, 6);

    bar();
    bar();
    bar();
}
