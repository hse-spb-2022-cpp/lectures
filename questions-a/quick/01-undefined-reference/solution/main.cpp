#include <cassert>
#include "triple.hpp"

int main() {
    const Triple t{1, 2, 3};
    t.print();
    assert(t.sum() == 1 + 2 + 3);
}
