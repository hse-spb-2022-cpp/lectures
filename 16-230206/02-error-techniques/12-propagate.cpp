#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

enum class read_vector_error { OK, CANNOT_OPEN, CANNOT_READ_LENGTH, CANNOT_READ_NUMBER };

read_vector_error read_vector(const std::string &filename, std::vector<int> &result) {
    std::ifstream f(filename);
    if (!f) {
        return read_vector_error::CANNOT_OPEN;
    }

    int n;
    if (!(f >> n)) {
        return read_vector_error::CANNOT_READ_LENGTH;
    }

    std::vector<int> vec(n);
    for (int &v : vec) {
        if (!(f >> v)) {
            return read_vector_error::CANNOT_READ_NUMBER;
        }
    }
    result = std::move(vec);
    return read_vector_error::OK;
}
