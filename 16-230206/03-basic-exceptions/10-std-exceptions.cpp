#include <boost/core/demangle.hpp>
#include <exception>
#include <iostream>
#include <vector>
#include <string>

struct Base { virtual ~Base() = default; };
struct Derived1 : Base {};
struct Derived2 : Base {};

int main() {
    try {
        // Some are std::runtime_error, some are std::logic_error, some are neither.
        // std::vector<int> vec(-1);  // std::bad_alloc
        {
            Derived1 d1;
            Base &b = d1;
            [[maybe_unused]] Derived2 *d2a = dynamic_cast<Derived2*>(&b);  // nullptr
            std::cout << d2a << "\n";
            [[maybe_unused]] Derived2 &d2b = dynamic_cast<Derived2&>(b);  // std::bad_cast
        }
        // std::cout << std::stoi("123") << "\n";
        // std::cout << std::stoi("foo") << "\n";  // std::invalid_argument
        // std::cout << std::vector<int>(10).at(15) << "\n";  // std::out_of_bounds
        // See Boost::Dll example with 'file not found'
    } catch (const std::exception &e) {
        std::cout << "Error type=" << boost::core::demangle(typeid(e).name()) << " what()=" << e.what() << "\n";
    }
}
