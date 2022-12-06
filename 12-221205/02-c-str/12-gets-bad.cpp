#include <cstdio>
#include <iostream>

int main() {
    const int MAX_LEN = 10;
    char buf[MAX_LEN + 1];
    gets(buf);  // DANGEROUS
    std::cout << "buf=|" << buf << "|\n";
    // Top-1 vulnerability: https://ulearn.me/course/hackerdom/Perepolnenie_steka_3bda1c2c-c2a1-4fb0-9146-fccc47daf93b
}
