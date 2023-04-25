#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *s = malloc(5), *new_s = malloc(50);
    strcpy(s, "xyz");
    printf("%p %s; new_s=%p\n", s, s, new_s);

    s = realloc(s, 4);
    printf("%p %s\n", s, s);

    // FIXME: what is the problem?
    // https://pvs-studio.com/en/w/v701/
    // https://habr.com/ru/company/pvs-studio/blog/343508/
    s = realloc(s, 6);
    printf("%p %s\n", s, s);

    s = realloc(s, 100);
    printf("%p %s\n", s, s);

    s = realloc(s, 1000);
    printf("%p %s\n", s, s);

    s = realloc(s, 1);
    printf("%p %s\n", s, s);  // Technically UB.

    free(s);
}
