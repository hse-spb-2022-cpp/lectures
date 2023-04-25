#include <stdio.h>
#include <stdlib.h>

void my_memcpy1(void *restrict dst, const void *restrict src, size_t n) {
    // src:  0 1 2 3 4 5
    // dst:      2 3 4 5 6 7

    // restrict: dst/src do not intersect and do not point to &n.
    while (n-- > 0)
        *(char *)dst++ = *(const char *)src++;
}

void my_memcpy2(void *restrict dst, const void *restrict src, size_t n) {
    for (size_t i = n; i > 0; i--) {
        ((char *)dst)[i - 1] = ((const char *)src)[i - 1];
    }
}

int main(void) {
    {
        int arr[] = {1, 2, 3, 4, 5};
        my_memcpy1(arr, arr + 2, sizeof(int) * 3);  // Bad call: restrict is violated
        for (int i = 0; i < 5; i++) {
            printf("%d%c", arr[i], "\n "[i + 1 < 5]);
        }
    }
    {
        int arr[] = {1, 2, 3, 4, 5};
        my_memcpy2(arr + 2, arr, sizeof(int) * 3);  // Bad call: restrict is violated
        for (int i = 0; i < 5; i++) {
            printf("%d%c", arr[i], "\n "[i + 1 < 5]);
        }
    }
    // memcpy: no intersections
    // memmove: allows intersections
}
