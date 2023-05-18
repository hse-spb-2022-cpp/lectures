#include <vector>
#include <utility>

using vi1 = std::vector<int>;
typedef std::vector<int> vi2;

// v<T> = std::vector<T>;
template<typename T>
using v = std::vector<T>;
// `using` only, not with `typedef`

template<typename T1, typename T2>
using vp = std::vector<std::pair<T1, T2>>;

int main() {
    v<int> v;
    vp<int, int> v2;
}
