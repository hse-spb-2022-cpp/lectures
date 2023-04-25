#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *a = malloc(5 * sizeof(int));  // new int[5];
    assert(a);  // returns NULL/0 on failure, `nullptr` is missing TODO
    // malloc returns void*, implicitly casted to int* in C
    printf("%d\n", a[0]);  // Uninitialized, UB. Typically zero on Linux.
    a[0] = 10;  // No need in placement new.
    printf("%d\n", a[0]);
    free(a);  // delete[] a

    int *b = malloc(0);  // implementation-defined
    printf("%p\n", b);
    free(b);

    int *c = calloc(5, sizeof(int));  // zeroes memory, new int[5]{}
    printf("%d\n", c[0]);
    free(c);
}
