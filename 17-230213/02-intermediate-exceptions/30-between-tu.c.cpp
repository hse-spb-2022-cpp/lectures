#include <exception>

struct my_error : std::exception {
    const char *what() const noexcept override {
        return "my_error";
    }
};

void bar(int i) {
    if (i == 3) {
        throw my_error();
    }
}
