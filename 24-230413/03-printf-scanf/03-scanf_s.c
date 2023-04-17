#include <stdio.h>

int main() {
    {
        char buf[5];
        int cnt = scanf("%s", buf);  // Potentially UB
        printf("cnt=%d, buf=|%s|\n", cnt, buf);
    }
    {
        char buf[5];
        int x;
        int cnt = scanf("%4s%d", buf, &x);  // No UB, will stop reading after 4 bytes.
        printf("cnt=%d, buf=|%s|, x=%d\n", cnt, buf, x);
    }
#ifdef __WIN32__  // It's in C11, but is not supported by libstdc++/libc++
    {
        char buf[5];
        int cnt = scanf_s("%s", buf, (rsize_t)sizeof buf);  // No UB, will call "constraint handler" (implementation-defined) and fail reading.
        printf("cnt=%d, buf=|%s|\n", cnt, buf);
    }
#endif
}
