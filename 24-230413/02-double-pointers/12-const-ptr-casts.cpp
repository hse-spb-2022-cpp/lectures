#include <cassert>

int main() {
    int x[10]{};
    const int cx[10]{};

    int *px = &x[0];  // not &cx[0]
    const int *pcx = &cx[0];  // or &x[0]

    // https://isocpp.org/wiki/faq/const-correctness#constptrptr-conversion

    [[maybe_unused]] int **ppx = &px;  // ok
    // ppx = &pcx;  // const int** --> int**: error, otherwise `**ppx = 10;` modifies the const array

    const int **ppcx = &pcx;
    // ppcx = &px;  // int** --> const int**: error, otherwise:
    *ppcx = &cx[0];  // Makes `int*` point to `const int*`.
    if (px == &cx[0]) {
        *px = 10;  // Oops, modified const array.
    }

    [[maybe_unused]] const int *const *pcpcx = &px;
    // int** --> const int * const *: ok
    // *pcpcx = &cx[0];
}
