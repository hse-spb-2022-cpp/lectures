#include <vector>
#include <utility>

// function template
template<typename T>
void swap(T &a, T &b) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

struct unmovable {
    unmovable() = default;
    unmovable(const unmovable &) = delete;
    unmovable(unmovable &&) = delete;
    unmovable &operator=(const unmovable &) = delete;
    unmovable &operator=(unmovable &&) = delete;
    ~unmovable() = default;
};

int main() {
    int x, y;
    swap(x, y);

    unmovable a, b;
    swap(a, b);
}
