#include <exception>
#include <stdexcept>
#include <vector>
#include <iostream>

// !!! Modification 1
struct invalid_vector_format : std::runtime_error {
    invalid_vector_format() : std::runtime_error("Invalid vector format") {}
};

std::vector<int> read_vector() {
    int n;
    if (!(std::cin >> n)) {
        throw invalid_vector_format();
    }
    std::vector<int> result(n);
    for (int i = 0; i < n; i++) {
        if (!(std::cin >> result[i])) {
            throw invalid_vector_format();
        }
    }
    return result;
}

void write_answer(const std::vector<int> &vec) {
    for (std::size_t i = 0; i < vec.size(); i++) {
        if (i) std::cout << " ";
        std::cout << vec[i];
    }
    std::cout << "\n";
}

void rethrow() {
    std::cout << "Rethrowing...\n";
    throw;
}

void solve() {
    std::vector<int> a;
    // !!! Modification 2
    try {
        a = read_vector();
    } catch (const invalid_vector_format &e) {
        std::cout << "Caught error while reading vector a, propagating...\n";
        // throw e;  // rethrow exception 'e', but what about other types?
        // throw;  // does the same
        rethrow();  // does the same, but indirectly
    }
    std::vector<int> b;
    // !!! Modification 3
    try {
        b = read_vector();
    } catch (...) {
        std::cout << "Caught error while reading vector b, propagating...\n";
        throw;  // works with `...`
    }
    
    std::vector<int> answer = a;
    answer.insert(answer.end(), b.begin(), b.end());

    write_answer(answer);
}

int main() {
    try {
        solve();
    } catch (const std::exception &err) {  // !!! Modification 4
        std::cout << err.what() << "\n";
    }
}
