#include <vector>
#include <utility>

// function template
template<typename T>
void swap(T &a, T &b) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

struct uncopyable {
    uncopyable() = default;
    uncopyable(const uncopyable &) = delete;
    uncopyable(uncopyable &&) = delete;
    uncopyable &operator=(const uncopyable &) = delete;
    uncopyable &operator=(uncopyable &&) = delete;
    ~uncopyable() = default;
};

int main() {
    int x, y;
    swap(x, y);

    uncopyable a, b;
    swap(a, b);
}
