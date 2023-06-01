#include <cstddef>
#include <string>

// There is literally no way to "index" the parameter pack. Recursion via specialization only:
template<typename... Ts>
struct tuple {};

template<typename Head, typename... Tail>
struct tuple<Head, Tail...> {  // For non-empty lists.
    Head head{};
    tuple<Tail...> tail;  // Some use inheritance instead so EBO (Empty Base Optimization) is enabled.
};

template<std::size_t I, typename ...Ts>
const auto &get(const tuple<Ts...> &t) {
    // Since C++17
    if constexpr (I == 0) return t.head;
    else                  return get<I - 1>(t.tail);
}

int main() {
    tuple<int, std::string> x;
    [[maybe_unused]] auto a = x;  // tuple<int, std::string>
    [[maybe_unused]] auto b = x.head;  // int
    [[maybe_unused]] auto c = x.tail;  // tuple<std::string>
    [[maybe_unused]] auto d = x.tail.head;  // std::string
    [[maybe_unused]] auto e = x.tail.tail;  // tuple<>
    // [[maybe_unused]] auto f = x.tail.tail.head;  // compilation error

    [[maybe_unused]] int f1 = get<0>(x);
    [[maybe_unused]] std::string f2 = get<1>(x);
}
