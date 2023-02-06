#include <cstddef>
#include <vector>
#include <iostream>

struct invalid_vector_format {};

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

void solve() {
    std::vector<int> a = read_vector();  // if exception is thrown, it's propagated
    std::vector<int> b = read_vector();  // if exception is thrown, it's propagated; local variables are cleaned up (stack unwind, раскрутка стека).
    
    // Тут какие-то вычисления
    std::vector<int> answer = a;
    answer.insert(answer.end(), b.begin(), b.end());

    write_answer(answer);
}

int main() {
    try {
        solve();  // if exception is thrown, it's propagated
    } catch (const invalid_vector_format &err) {  // looking for the first catch
        std::cout << "Invalid vector format\n";
        // Print good error message is hard:
        // 1. How exactly the format is invalid? We could add it to the exception.
        // 2. We don't have much context here: what exactly failed? A or B?
        // 3. We don't have that context in read_vector() either.
    }
}
