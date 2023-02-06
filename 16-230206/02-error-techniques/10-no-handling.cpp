#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<int> read_vector(const std::string &filename) {
    std::ifstream f(filename);
    assert(f);  // Why no handling?
    int n;
    f >> n;
    assert(f);
    std::vector<int> vec(n);
    for (int &v : vec) {
        f >> v;
        assert(f);
    }
    return vec;
}
