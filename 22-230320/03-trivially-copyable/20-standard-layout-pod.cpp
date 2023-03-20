#include <cstddef>
#include <iostream>

// StandardLayout: https://en.cppreference.com/w/cpp/named_req/StandardLayoutType
// https://docs.microsoft.com/en-us/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170
// No virtual functions/bases, no base duplicates, some extra reqs for base classes vs first members.
// All non-static members (fields):
// 1. Are in the same struct
// 2. Has the same access.
// 3. StandardLayout themselves or scalar types (no references).
//
// No requirements about destructors/copy ctors...
//
// StandardLayout means "interoperable with other languages such as C".
// StandardLayout && TriviallyCopyable == POD (Plain Old Data).

struct EmptyBase {
    void foo() {}
};

struct IsStandardLayout : EmptyBase {
protected:
    int x = 1;
    char y = 2;
    int z = 3;
};

struct AlsoStandardLayout : IsStandardLayout {
    void bar() {}
};

struct NotStandardLayout1 : AlsoStandardLayout {
    int foo = 4;
};

struct NotStandardLayout2 {
private:
    int x = 1;
public:
    int y = 2;
private:
    int z = 3;
};

void print_bytes(unsigned char *bytes, std::size_t length) {
    for (std::size_t i = 0; i < length; i++) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << static_cast<int>(bytes[i]);
    }
    std::cout << '\n';
}

int main() {
    EmptyBase e;
    IsStandardLayout isl;
    AlsoStandardLayout asl;
    NotStandardLayout1 nsl1;
    NotStandardLayout2 nsl2;
    print_bytes(reinterpret_cast<unsigned char*>(&e), sizeof e);
    print_bytes(reinterpret_cast<unsigned char*>(&isl), sizeof isl);
    print_bytes(reinterpret_cast<unsigned char*>(&asl), sizeof asl);
    print_bytes(reinterpret_cast<unsigned char*>(&nsl1), sizeof nsl1);
    print_bytes(reinterpret_cast<unsigned char*>(&nsl2), sizeof nsl2);
}
