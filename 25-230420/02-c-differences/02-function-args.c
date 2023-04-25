#include <stdio.h>

void foo(char* a) {
    printf("%s\n", a);
}

void bar() {   // Any arguments!
}

void baz(void) {   // No arguments
}

int main(void) {
    foo("hello");
    // foo("hello", "world");  // compilation error
    bar(1, 2, 3, "wow");
    baz();
    // baz(1, 2, 3);  // compilation error
}
