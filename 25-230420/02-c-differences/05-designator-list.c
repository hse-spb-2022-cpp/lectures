#include <stdio.h>

struct point {
    int x, y, z;
};

#define INIT_ARR [0] = 55, [1] = 56

int main(void) {
    // zero everything except `x` and `y`
    struct point p = {.z = 10, .y = 20};
    printf("p=%d %d %d\n", p.x, p.y, p.z);

    // https://docs.python.org/3/extending/newtypes_tutorial.html#defining-new-types
    int arr[10] = {INIT_ARR, [3] = 5, [5] = 10};
    for (int i = 0; i < 10; i++) {
        printf("arr[%d]=%d\n", i, arr[i]);
    }
    // int arr2[10] = {1, 2, 3};
}
