#include <vector>
#include <utility>

// function template
template<typename T>
void swap(T &a, T &b) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

int main() {
    int x, y;
    [[maybe_unused]] short z;
    swap<int>(x, y);
    swap<int>(x, z);  // compilation error: cannot bind int& to short
}
