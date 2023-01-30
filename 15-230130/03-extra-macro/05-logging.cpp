#include <iostream>

int foo() {
    std::cout << "Works a lot!\n";
    return 10;
}

bool logging_enabled = true;

#define LOG !logging_enabled ? std::cout : std::cout

int main() {
    if (logging_enabled) {
        std::cout << foo() << "\n";
    }
    LOG << foo() << "\n";
}
// TODO: show why not func
