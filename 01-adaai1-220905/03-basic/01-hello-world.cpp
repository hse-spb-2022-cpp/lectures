#include <iostream>  // Akin to `import` in Python/Java, details later

// Top-level: no code, only functions/global variables/#include/etc

int main() {  // entry point, the `main` function
    std::cout << "Hello World\n";  // printing to the "standard output" of the program
                                   // only double quotes, escaping with \ works
    return 0;  // any application has an "exit code", 0 is "success" by convention,
               // everything else is typically "runtime error"
}
