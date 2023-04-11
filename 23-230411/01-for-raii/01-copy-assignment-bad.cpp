#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <utility>

struct str {
    std::size_t capacity;
    char *data;

public:
    str() : data(nullptr) {
    }

    str(const char *other)
        : capacity(other ? std::strlen(other) + 1 : 0),
          data(capacity ? new char[capacity] : nullptr) {
        if (data) {
            std::strcpy(data, other);
        }
    }

    str(const str &other) : str(other.data) {
    }

    str(str &&other) noexcept 
        : capacity(std::exchange(other.capacity, 0)),
          data(std::exchange(other.data, nullptr)) {
    }

    str &operator=(str &&other) noexcept {
        std::swap(capacity, other.capacity);
        std::swap(data, other.data);
        return *this;
    }

    str &operator=(const str &other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        capacity = other.capacity;
        data = capacity ? new char[capacity] : 0;  // Throws?
        std::strcpy(data, other.data);
        return *this;
    }

    ~str() {
        delete[] data;
    }

    const char *get() const noexcept {
        return data;
    }
};

int main() {
    str a = "hello";
    str b = "world";
    b = b;
    a = b;
    str c = std::move(a);
    std::cout << c.get() << "\n";  // world
}
