#include "print.h"

void foo();

int main() {
    foo();
    print(10);

    Printer p = {239};
    p.print();
    p.foo();
}
