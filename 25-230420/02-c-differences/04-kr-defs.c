#include <stdio.h>

/* K&R (old-style) function definitions are allowed (deleted in C23). Use never. */
void foo(a, b)
int a; char b;
{
    printf("a=%d, b=%c\n", a, b);
}

void bar(int a, char b) {
    printf("a=%d, b=%c\n", a, b);
}

int main() {
    foo(123, 'x');
    bar(456, 'y');
}
