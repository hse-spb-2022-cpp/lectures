#include <iostream>
#include <vector>

struct B {
    std::vector<int> vec{10, 20, 30};
};

struct A {
    std::vector<B> bs = std::vector<B>(5);
};

int main() {
    A x;
    A y = x;
    std::cout << x.bs[0].vec[1] << "\n";
    std::cout << y.bs[0].vec[1] << "\n";
    x.bs[0].vec[1]++;
    std::cout << x.bs[0].vec[1] << "\n";
    std::cout << y.bs[0].vec[1] << "\n";
}
