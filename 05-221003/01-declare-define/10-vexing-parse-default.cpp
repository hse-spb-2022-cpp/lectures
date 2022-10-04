#include <iostream>
#include <vector>

// The most vexing parse
struct Foo {
    int x{};  // ok: default initialization, i.e. 0
    int y();  // the most vexing parse: function?????
};

int main() {
    Foo f;
    f.x = 10;
    f.y = 10;

    std::vector<int> v1{};
    std::vector<int> v2(10);
    std::vector<int> v3();
    std::vector<int> v4;

    std::cout << v1.size() << "\n";
    std::cout << v2.size() << "\n";
    std::cout << v3.size() << "\n";
}
