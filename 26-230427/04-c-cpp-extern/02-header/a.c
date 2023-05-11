#include <stdio.h>
#include "a.h"
#include "b.h"

int foo(void) {
    int arr[] = { [3] = 123 };  // Use C-specific syntax to ensure we're writing C.
    return arr[3];
}

int main(void) {
    printf("hello\n");
    return my_main();
    // return my_main(1, 2, 3);  // Should not compile!
}
