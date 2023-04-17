#include <iostream>

//void foo(const char *strs[]) {
void foo(const char **strs) {
    std::cout << strs[0] << " " << strs[1] << "\n";
}

int main(int argc, char *argv[]) {
    const char *strs[] = {
        "Hello from ",
        "World"
    };
    foo(strs);

    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << "\n";
    }
}
