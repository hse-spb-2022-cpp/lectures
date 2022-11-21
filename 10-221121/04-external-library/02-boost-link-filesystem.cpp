#include <boost/filesystem/operations.hpp>
#include <iostream>

namespace fs = boost::filesystem;

int main() {
    std::cout << "Current directory is: " << fs::current_path() << "\n";
    std::cout << "Content is:\n";
    for (const auto &f : fs::directory_iterator(fs::current_path())) {
        std::cout << f.path().filename() << "\n";
    }
}
