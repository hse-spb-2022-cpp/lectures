#include <stdlib.h>
#include <stdio.h>

int main() {
    // "opaque" pointer
    FILE *f = fopen("02-opaque-pointers.c", "r");  // "constructor", resources are allocated by the library.

    // Never try to access `FILE`'s fields directly.
    char buf[20];
    fscanf(f, "%20s", buf);  // "method"
    printf("buf=|%s|\n", buf);

    fclose(f);  // "destructor"
}
