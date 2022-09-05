#include <iostream>

int a = 10, b = 20;

int main() {
    std::cout << a + b << "\n";  // 30
    {  // new scope
        std::cout << a << " " << b << "\n";  // 10 20
        int a = 5;  // "shadows" the global variable, I dislike this style
        std::cout << a << " " << b << "\n";  // 5 20
        // int a = 100;  // cannot make another variable in the same scope
        {
            int a = 6;  // "shadows" the local variable
            std::cout << a << "\n";  // 6
        }
        std::cout << a << "\n";  // 5
    }
    std::cout << a << "\n";  // 10
}
