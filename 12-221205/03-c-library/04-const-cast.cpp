#include <cassert>
#include <iostream>

int len(char *s) {
    int l = 0;
    while (s[l] != '\0') {
        l++;
    }
    return l;
}

void update(char *s) {
    s[0] = 'h';
}

int main() {
    const char *s = "hello";
    // assert(len(s) == 5);  // compilation error
    assert(len(const_cast<char*>(s)) == 5);  // ok

    update(const_cast<char*>(s));  // ub
}
