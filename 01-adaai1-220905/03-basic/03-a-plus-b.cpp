#include <iostream>

int main() {
    /* variable declaration: type of a variable is always fixed
       type is a pair of (possible values, possible operations) */
    int a, b;
    a = 5;  // ok
    std::cin >> a >> b;
    std::cout << a + b << std::endl;

    // Alternative
    int s = a + b;  // declare variable right before it's needed please!
    std::cout << s << std::endl;
}
