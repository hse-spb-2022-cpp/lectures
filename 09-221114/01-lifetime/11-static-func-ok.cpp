#include <cassert>

int counter() {
    static int calls = 10;
    return ++calls;
}

int main() {
    assert(counter() == 11);
    assert(counter() == 12);
    assert(counter() == 13);
    assert(counter() == 14);
}
