#include <algorithm>
#include <iostream>
#include <cstddef>

#pragma pack(push, 1)
struct S {
    char c;
    // no padding [bytes], alignment [of fields] is invalid
    int a = 10, b = 20;
};
#pragma pack(pop)

int main() {
    std::cout << sizeof(int) << " " << alignof(int) << "\n";
    std::cout << sizeof(std::uint32_t) << " " << alignof(std::uint32_t) << "\n";
    std::cout << sizeof(int*) << " " << alignof(int*) << "\n";

    // https://stackoverflow.com/questions/8568432/is-gccs-attribute-packed-pragma-pack-unsafe
    // One should not create a reference/pointer to a wrongly aligned object.
    // May fail even on x86_64 because of optimizations: https://stackoverflow.com/a/46790815/767632

    S s;
    s.a = 30;  // No references, the compiler knows that `s.a` is unaligned.
    std::cout << s.a << " " << s.b << "\n";  // No references because operator<< takes by value.
    std::swap(s.a, s.b);  // Unaligned references to `int`: UB, undefined sanitizer is right.
    [[maybe_unused]] int *aptr = &s.a;  // Unaligned pointer to `int`: UB, no undefined sanitizer warning :(
    *aptr = 40;
}
