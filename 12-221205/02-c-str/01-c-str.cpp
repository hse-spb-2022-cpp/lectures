#include <cstring>
#include <iterator>
#include <iostream>

// C-style string / строки в стиле си / сишные строки
// null-terminated string
// ASCIIZ string

int main() {
    /*const*/ char str[] = "hello";  // const is optional: we're copying "hello" into a local array with automatic storage duration.
    // char str[] = {'h', 'e', 'l', 'l', 'o', 0};
    std::cout << std::strlen(str) << "\n";  // 5
    std::cout << std::size(str) << "\n";  // 6
    std::cout << sizeof(str) / sizeof(str[0]) << "\n";  // 6
    std::cout << str << "\n";

    int int_value = 5;
    int *int_ptr = &int_value;
    const char *str_ptr = str;  // array-to-pointer decay
    // std::cout << std::size(str_ptr) << "\n";  // does not compile
    std::cout << int_ptr << " " << str_ptr << "\n";
    std::cout << static_cast<const void*>(str_ptr) << "\n";

    const char *str_ptr2 = &str[2];
    std::cout << str_ptr2 << "\n";

    const char strs[] = "hello\0world\0botva";
    std::cout << std::size(strs) << "\n";  // 18
    std::cout << strs << "\n";
    std::cout << &strs[1] << "\n";
    std::cout << &strs[6] << "\n";
    std::cout << &strs[12] << "\n";
}
