#include <iostream>
#include <fstream>
#include <type_traits>

// https://stackoverflow.com/questions/4178175/what-are-aggregates-and-pods-and-how-why-are-they-special (C++03 and C++11)
// https://en.cppreference.com/w/cpp/named_req/TriviallyCopyable
// Trivially copyable: scalar types or a class such that:
// 1. Destructor is trivial (for class, bases, members)
// 2. There is copy/move ctor/assignment operator
// 3. All copy/move are trivial (for class, bases, members)
// 4. No virtual functions, no virtual base classes.
//
// Constructors and methods are allowed.

struct MyTriviallyCopyable {
    int x = 10;
    char y = 20;
    // Compiler may add padding: 3 bytes so 'z' is 4-bytes aligned.
    float z = 30;
};

static_assert(std::is_trivially_copyable_v<MyTriviallyCopyable>);

int main() {
    MyTriviallyCopyable p;
    std::ofstream f("01.bin", std::ios_base::out | std::ios_base::binary);
    // Not UB.
    f.write(reinterpret_cast<const char*>(&p), sizeof(p));
}
