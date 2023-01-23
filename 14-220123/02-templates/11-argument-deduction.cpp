#include <vector>
#include <utility>

// function template
template<typename T>
void swap(T &a, T &b) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

template<typename T, typename U>
void foo(const std::vector<T> &, const std::vector<U> &) {
}

int main() {
    int x, y;
    [[maybe_unused]] short z;
    // template argument deduction
    swap(x, y);  // Arg1=int, Arg2=int => T = int
    // swap(x, z);  // compilation error: deduced conflicting types for T
    foo(std::vector<double>{}, std::vector<float>{});  // T=double, U=float
}
