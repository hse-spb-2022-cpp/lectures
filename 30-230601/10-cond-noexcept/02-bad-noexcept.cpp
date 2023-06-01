#include <cstddef>
#include <memory>
#include <optional>
#include <iostream>
#include <string>
#include <type_traits>

template<typename T>
struct vector {
    T *data;
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

template<typename T>
struct optional {
    alignas(T) char bytes[sizeof(T)];
    bool exists = false;

    optional() = default;
    ~optional() { reset(); }

    T &data() { return reinterpret_cast<T&>(bytes); }
    const T &data() const { return reinterpret_cast<const T&>(bytes); }

    void reset() {
        if (exists) {
            data().~T();
            exists = false;
        }
    }
    optional &operator=(const optional &other)
        // default is bad, optional<int> is not nothrow-copyable
        // noexcept  // optional<std::string> is not nothrow-copyable
        noexcept(std::is_nothrow_copy_constructible_v<T>)  // ok, conditional noexcept-qualifier
    {
        if (this == &other) {
            return *this;
        }
        reset();
        if (other.exists) {
            new (bytes) T(other.data());
            exists = true;
        }
        return *this;
    }
};

int main() {
    {
        vector<optional<int>> v1, v2;
        v1 = v2;  // naive copy assignment
    }
    {
        vector<optional<std::string>> v1, v2;
        v1 = v2;  // creating a new buffer???
    }
    // can uncomment to test during compilation
    static_assert(std::is_nothrow_copy_assignable_v<optional<int>>);
    static_assert(!std::is_nothrow_copy_assignable_v<optional<std::string>>);
}
