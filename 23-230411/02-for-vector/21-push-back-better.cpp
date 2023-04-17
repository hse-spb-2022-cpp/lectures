#include <string>
#include <utility>

template<typename T>
struct stub_vector {
    alignas(alignof(T)) char data[sizeof(T) * 3];
    int size = 0;

    T &operator[](int i) {
        return reinterpret_cast<T&>(data[i * sizeof(T)]);
    }

    void push_back(T value) {
        new (&(*this)[size]) T(std::move(value));
        ++size;
    }

    ~stub_vector() {
        for (int i = 0; i < size; i++) {
            (*this)[i].~T();
        }
    }
};

int main() {
    stub_vector<std::string> vec;
    std::string foo = "hello";
    vec.push_back(foo);  // 1 copy, 1 move
    vec.push_back(std::string(10'000, 'x'));  // 1 creation, 2 move
}
