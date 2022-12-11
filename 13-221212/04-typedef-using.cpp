#include <vector>
#include <utility>
#include <typeinfo>
#include <iostream>

typedef std::vector<int> vi;
using pii = std::pair<int, int>;
// Please do not #define: it does not respect namespaces/private/public
// https://stackoverflow.com/a/1666375/767632

int main() {
    vi v1(10);
    std::vector<int> &v2 = v1;
    std::cout << typeid(v1).name() << "\n";
    std::cout << typeid(v2).name() << "\n";

    pii p1(10, 20);
    std::pair<int, int> &p2 = p1;
}
