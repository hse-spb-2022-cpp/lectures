#include "optimization.h"

int main() {
    const int MAX_LEN = 10;
    char buf[MAX_LEN + 1];
    readWord(buf);  // Careful: do not overflow the buffer
                    // UB otherwise, see https://en.wikipedia.org/wiki/Buffer_overflow
                    // Solution: do not use 'readWord', use 'fgets' instead of 'gets'
                    // Also see https://ulearn.me/Course/Hackerdom
}
