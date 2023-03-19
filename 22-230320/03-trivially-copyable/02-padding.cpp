#include <iostream>
#include <fstream>

#pragma pack(push, 1)
// Padding is disabled. We still have troubles with:
// 1. Endianness: order of bytes inside 'int'. E.g. x86 is "little-endian", some are "big-endian": old Mac, some 'mips' routers (not 'mipsel').
// 2. Not all CPUs may read unaligned memory: ""Anybody who writes #pragma pack(1) may as well just wear a sign on their forehead that says “I hate RISC”: https://devblogs.microsoft.com/oldnewthing/20200103-00/?p=103290
// 3. Exact sizes of int/float (use std::uint8_t and stuff).
struct MyPod {
    int x = 10;
    char y = 20;
    float z = 30;
};
#pragma pack(pop)

int main() {
    MyPod p;
    std::ofstream f("02.bin", std::ios_base::out | std::ios_base::binary);
    // Not UB.
    f.write(reinterpret_cast<const char*>(&p), sizeof(p));
}
