#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <string>

void check_file(const std::string &filename) {
    FILE *f = std::fopen(filename.c_str(), "r");
    std::cout << "Reading from " << filename << "\n";
    std::cout << "    f: " << f << ", errno: " << errno << " " << std::strerror(errno) << "\n";  // POSIX (not C/C++) requires that errno macro is set.
    // Problem: have to check immediately after each function. Does not propagate up.
    if (f == nullptr) {
        return;
    }
    for (;;) {
        int x = -239;
        int read = fscanf(f, "%d", &x);  // Still easy to forget to check.
        std::cout << "    x = " << x << ", read = " << read << ", errno = " << errno << " " << std::strerror(errno) << "\n";
        if (read != 1) {
            break;
        }
    }
    fclose(f);
}

int main() {
    check_file("numbers-01-simple.in");
    check_file("numbers-02-immediate-eof.in");
    check_file("does-not-exist.in");
}
