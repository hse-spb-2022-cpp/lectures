#include <cassert>

void func() {}

int main() {
    int buf[10];
    void *ptr = buf;
    void *ptr2 = ptr + 5;  // GCC extension! Only a warning in GCC, error in Clang.
    assert(ptr2 == static_cast<char*>(ptr) + 5);
}
