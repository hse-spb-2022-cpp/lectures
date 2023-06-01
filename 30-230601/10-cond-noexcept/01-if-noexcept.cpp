#include <cstddef>
#include <optional>
#include <iostream>
#include <string>
#include <type_traits>

template<typename T>
struct vector {
    T *data = nullptr;
    std::size_t len = 0;

    vector() = default;
    vector(const vector &) = default;
    vector(vector &&) = default;

    vector &operator=(vector &&) = default;
    vector &operator=(const vector &other) {
        if (this == &other) {
            return *this;
        }
        // NOTE: two separate algorithms for providing a strong exception safety
        if constexpr (std::is_nothrow_copy_assignable_v<T>) {
            // Never throws (like in lab10)
            std::cout << "naive copy assignment\n";
            for (std::size_t i = 0; i < len && i < other.len; i++) {
                data[i] = other.data[i];
            }
            // ...
        } else {
            std::cout << "creating a new buffer\n";
            // May actually throw, cannot override inidividual elements, should allocate a new buffer.
            *this = vector(other);
        }
        return *this;
    }
};

int main() {
    {
        vector<int> v1, v2;
        v1 = v2;  // naive copy assignment
    }
    {
        vector<std::optional<int>> v1, v2;
        v1 = v2;  // naive copy assignment
    }
    {
        vector<std::string> v1, v2;
        v1 = v2;  // creating a new buffer
    }
    {
        vector<std::optional<std::string>> v1, v2;
        v1 = v2;  // creating a new buffer
    }
    {
        vector<vector<int>> v1, v2;
        v1 = v2;  // creating a new buffer
    }
}
