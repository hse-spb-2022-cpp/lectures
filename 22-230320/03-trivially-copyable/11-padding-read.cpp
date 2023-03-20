#include <iostream>
#include <fstream>

#pragma pack(push, 1)
struct MyPod {
    int x = 100;
    char y = 200;
    float z = 300;
};
#pragma pack(pop)

int main() {
    MyPod p;
    std::ifstream f("10.bin", std::ios_base::out | std::ios_base::binary);
    // Not UB.
    f.read(reinterpret_cast<char*>(&p), sizeof(p));
    std::cout << p.x << " " << static_cast<int>(p.y) << " " << p.z << "\n";
}
