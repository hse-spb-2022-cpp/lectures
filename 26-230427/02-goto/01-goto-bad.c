#include <stdio.h>

// Go To Statement Considered Harmful:
// https://homepages.cwi.nl/~storm/teaching/reader/Dijkstra68.pdf

// GOTOphobia considered harmful in C:
// https://blog.joren.ga/gotophobia-harmful
// https://news.ycombinator.com/item?id=34943952

// Even worse: http://www.1000bit.it/support/manuali/commodore/32_BASIC_Programs_for_the_PET_Computer.pdf (e.g. page 23 in PDF, page 7)

int main(void) {
    int n = 10;
    int i = 0;
label:
    printf("%d\n", i);
    i++;
    int x = 5;
    printf("  x=%d\n", x);
    x++;
    if (i < n)
        goto label;
    printf("end\n");

    {
    foo:;
    }
    {
    bar:
        int x;
    }
}
