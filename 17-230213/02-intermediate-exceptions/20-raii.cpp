#include <iostream>
#include <vector>

int main() {
    // RAII: Resource Acquisition Is Initialization
    {
        std::vector<int> v(1'000'000);
        // Invariant: v.size() == 1'000'000, memory allocation succeeded.
        v[999'999] = 123;
        // RAII part 1: constructor has to establish invariant and grab resources. Throw an exception if that's impossible. No exit codes.
    }  // RAII part 2: destructor has to free all resource.

    try {
        std::vector<int> v(100'000'000'000);
        // Invariant: memory allocation succeeded.
        v[99'999'999'999] = 123;
    } catch (std::bad_alloc &) {
        // Impossible to access 'v' with incorrect invariant!
        std::cout << "caught bad_alloc\n";
    }
    // Jargon: 'RAII' may only mean part 2: destructor cleans up everything.
    // Constructing object is less strict, see ifstream.

    // Other languages: `finally` block or special 'try-with-resources'
    // syntax (Java) or `with` statement (Python). In Go: `defer` statement.
}
