#include <cassert>
#include <vector>

/*
Substitution Failure Is Not An Error (SFINAE)

Standard jokes:
1. Segmentation Fault Is Not An Error
2. SFINAE отбивная
*/

template<typename T>
void duplicate_element(T &container, typename T::iterator iter) {
    container.insert(iter, *iter);
}

template<typename T>
void duplicate_element(T *array, T *element) {
   assert(array != element);
   *(element - 1) = *element;
}

int main() {
    std::vector a{1, 2, 3};
    duplicate_element(a, a.begin() + 1);
    assert((a == std::vector{1, 2, 2, 3}));

    int b[] = {1, 2, 3};
    duplicate_element(b, b + 1);  // Not a compilation error when we "try" the first
    // overload even though `int[]::iterator` does not exist. Substitution `T=int[]` failure, not an error.
    assert(b[0] == 2);
    assert(b[1] == 2);
    assert(b[2] == 3);
}
