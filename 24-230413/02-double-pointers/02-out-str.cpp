#include <cassert>
#include <iostream>

bool read_line(char **s) {
    *s = new char[10];  // Assume noexcept.
    // *s = new char[10]{};
    std::cin.read(*s, 9);  // Does not add zero terminator
    (*s)[std::cin.gcount()] = 0;
    return static_cast<bool>(std::cin);
}

bool read_line_buffered(char **s) {
    static char buffer[10];
    *s = buffer;
    std::cin.read(*s, 9);
    (*s)[std::cin.gcount()] = 0;
    return static_cast<bool>(std::cin);
}

int main() {
    [[maybe_unused]] bool result;

    char *s = nullptr;
    result = read_line(&s);
    assert(result);
    std::cout << s << "\n";
    delete[] s;

    result = read_line_buffered(&s);
    assert(result);
    std::cout << s << "\n";
    // delete[] s;  // No need, it points to a buffer.

    // Moral: easy to confuse what to clean up and how. Used very rarely.
}
