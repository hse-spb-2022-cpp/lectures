#include <utility>

 // Template parameter pack, but of values instead of types.
template<int ...Ns>
constexpr std::pair<int, int> sum() {
    return {(Ns + ...), sizeof...(Ns)};
}
static_assert(sum<1, 2, 3, 4>() == std::pair(10, 4));

int main() {}
