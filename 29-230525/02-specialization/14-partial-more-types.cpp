#include <iostream>
#include <vector>
#include <utility>

template<typename T>
struct store_first {
    T data;
    store_first(const T &t) : data(std::move(t)) {}
};

template<typename TEl>
struct store_first</*T=*/std::vector<TEl>> {
    TEl data;
    store_first(const std::vector<TEl> &v) : data(v.at(0)) {}
};

template<typename T, typename U>
struct store_first</*T=*/std::pair<T, U>> {
    T data;
    store_first(const std::pair<T, U> &p) : data(p.first) {}
};

int main() {
    store_first<int> a(10);
    store_first<std::vector<int>> b{std::vector{20, 30, 40}};
    store_first<std::pair<int, double>> c{std::pair{50, 60.5}};
    std::cout << a.data << " " << b.data << " " << c.data << "\n";
}
