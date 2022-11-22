#include <boost/core/demangle.hpp>
#include <iostream>
#include <vector>

int main() {
    std::cout << boost::core::demangle(typeid(std::vector<int>).name());
}
