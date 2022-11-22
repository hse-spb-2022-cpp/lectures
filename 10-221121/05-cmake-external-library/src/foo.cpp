#include "foo.hpp"
#include <boost/filesystem/operations.hpp>
#include <iostream>

namespace fs = boost::filesystem;

void foo() {
    std::cout << "Hello World\n";
    std::cout << "Current directory is: " << fs::current_path() << "\n";
}
