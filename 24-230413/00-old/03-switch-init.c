#include <stdio.h>

int main() {
    for (int x = 1; x <= 5; x++) {
        switch (x) {
            case 1:
                break;
            case 4:
                break;
            case 2: {
                [[maybe_unused]] int wtf0 = 10;
            } break;
            default: /* { */
                [[maybe_unused]] int wtf1 = 20;  // Compilation Error in C++
                                                // May be left uninitialized in C
                /* } */ break;
            case 3:
                printf("%d\n", wtf1);
                break;
        }
    }
}
