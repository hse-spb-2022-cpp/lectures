#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    // https://en.cppreference.com/w/c/io/fscanf
    char buf1[10], buf2[20];
    int x;
    int *px = &x;
    int read1 = scanf(" %9[^-]-%19s%*d%d", buf1, buf2, px);
    printf("read1=%d, *px=%d\n", read1, *px);

    float a;
    double b;
    int read2 = scanf("%f%lf", &a, &b);  // types should match!
    printf("read2=%d, a=%f, b=%f\n", read2, a, b);

    // https://en.cppreference.com/w/c/io/fprintf
    printf("buf1=|%s|\nbuf2=|%s|\nx=%d\n", buf1, buf2, x);
    printf("     01234567890123456789\nbuf1=%9s\nbuf2=%19s\nx=%05d\n", buf1,
           buf2, x);
    printf("\n% d\n% d\n% d\n", 0, 5, -5);
    printf("\n%+d\n%+d\n%+d\n", 0, 5, -5);
    printf("%010.3f\n", a);
    printf("%010.3f\n", b);  // not %lf! ellipsis conversions.
    printf("100%% done!\n");
}
