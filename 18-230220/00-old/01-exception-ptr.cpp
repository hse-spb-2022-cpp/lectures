#include <exception>
#include <iostream>

// https://habr.com/ru/post/160955/

struct my_exception {
    int value;
};

void foo(int x) {
    throw my_exception{x + 10};
}

int main() {
    try {
        foo(0);
    } catch (my_exception &e) {
        std::cout << "e=" << e.value << "\n";
    }

    std::exception_ptr err;  // shared_ptr<exception>
    // Can be created using std::make_exception_ptr or std::current_exception.
    auto save_exception = [&]() {
        // Can be called at any point in the programm, not necessarily right inside `catch`.
        // If there is no "current" exception, returns `exception_ptr{}`.
        err = std::current_exception();
    };

    try {
        std::cout << "before foo(1)\n";
        foo(1);
        std::cout << "after foo(1)\n";
    } catch (...) {
        std::cout << "saving exception...\n";
        save_exception();
        // Out-of-scope: one can build nested exceptions: https://en.cppreference.com/w/cpp/error/nested_exception
    }

    try {
        if (err) {
            // The only way to 'read' `exception_ptr`.
            std::rethrow_exception(err);  // Requires non-empty `err`.
        } else {
            std::cout << "no exception\n";
        }
    } catch (my_exception &e) {
        std::cout << "e=" << e.value << "\n";
    }
}
