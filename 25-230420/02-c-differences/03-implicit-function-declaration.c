// #include <stdio.h>
/*

f(1, 2, 3, 4, "foo") --> int f();
void *malloc() vs int malloc().
gcc thinks it's ok in C11 still
*/

int main(void) {
    printf("2 + 2 = %d\n", 4);  // Works: implicitly adds `int printf();`
    // botva(1, 2);  // Error in C99, link error in C89 (or GCC with C99+)
}
