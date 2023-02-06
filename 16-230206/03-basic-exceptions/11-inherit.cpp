#include <exception>
#include <stdexcept>
#include <iostream>

struct my_exception : std::exception {
    const char *what() const noexcept override {
        return "my_exception";
    }
};

struct my_runtime_error : std::runtime_error {  // Choice between runtime_error and logic_error is not strict.
    my_runtime_error() : std::runtime_error("yay! " + std::to_string(123)) {}
};

// TODO: guess what is wrong with `class my_runtime_error : std::runtime_error`

int main() {
    try {
        throw my_exception();
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
    }

    try {
        throw my_runtime_error();
    } catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }

    try {
        throw my_runtime_error();
    } catch (std::runtime_error &e) {
        std::cout << e.what() << "\n";
    }
}
