#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<int> read_vector(const std::string &filename) {
    std::ifstream f(filename);
    if (!f) {
        std::cerr << "Unable to open file\n";
        std::exit(1);
    }

    int n;
    if (!(f >> n)) {
        std::cerr << "Unable to read length of a vector\n";
        std::exit(1);
    }

    std::vector<int> vec(n);
    for (int &v : vec) {
        if (!(f >> v)) {
            std::cerr << "Unable to read number\n";
            std::exit(1);
        }
    }
    return vec;
}
