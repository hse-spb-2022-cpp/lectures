#include <vector>
#include <iostream>

#pragma pack(push, 1)
struct Foo {
//    char x;
    std::vector<int> v;
};
#pragma pack(pop)

int main() {
    Foo f;
    std::cout << alignof(f) << "\n";
    std::cout << alignof(std::vector<int>) << "\n";
    std::cout << static_cast<void*>(&f.v) << "\n";
}
