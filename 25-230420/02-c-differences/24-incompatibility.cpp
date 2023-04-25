#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // 1.
//  int *a = malloc(5 * sizeof(int));  // new int[5];
    int *a = static_cast<int*>(malloc(5 * sizeof(int)));  // new int[5];
    free(a);  // delete[] a

    // 2.
    // 'A' is int in C, char in C++.
    printf("%d %d\n", (int)sizeof('A'), (int)sizeof(char));
}
