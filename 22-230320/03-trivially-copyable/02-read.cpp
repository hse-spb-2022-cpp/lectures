#include <iostream>
#include <fstream>
#include <type_traits>

struct MyTriviallyCopyable {
    int x;
    char y;
    // Compiler may add padding: 3 bytes so 'z' is 4-bytes aligned.
    float z;
};

static_assert(std::is_trivially_copyable_v<MyTriviallyCopyable>);

int main() {
    MyTriviallyCopyable p;
    std::ifstream f("01.bin", std::ios_base::in | std::ios_base::binary);
    // Not UB.
    f.read(reinterpret_cast<char*>(&p), sizeof(p));
    std::cout << p.x << " " << static_cast<int>(p.y) << " " << p.z << "\n";
}
