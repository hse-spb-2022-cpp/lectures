#include <stdio.h>

int my_main(void);

int foo(void) {
    int arr[] = { [3] = 123 };  // Use C-specific syntax to ensure we're writing C.
    return arr[3];
}

int main(void) {
    printf("hello\n");
    return my_main();
}
