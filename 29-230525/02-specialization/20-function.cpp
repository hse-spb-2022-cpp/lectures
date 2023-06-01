#include <random>
#include <iostream>

std::mt19937 gen;

template<typename T>
T random(const T &from, const T &to);

template<>
int random<int>(const int &from, const int &to) {  // Argument types should match exactly: `const int &`, not just `int`.
    std::uniform_int_distribution<int> distrib(from, to - 1);
    return distrib(gen);
}

template<>
double random(const double &from, const double &to) {  // May actually omit template parameters if they're deduced from args
    std::uniform_real_distribution<double> distrib(from, to);
    return distrib(gen);
}

int main() {
    std::cout << random(1, 6) << "\n";  // T=int
    std::cout << random<int>(1, 6) << "\n";
    std::cout << random<int>(1, 6) << "\n";
    std::cout << "=====\n";
    std::cout << random(0.0, 1.0) << "\n";  // T=double
    std::cout << random<double>(0.0, 1.0) << "\n";
    std::cout << random<double>(0, 1) << "\n";
    // std::cout << random(0.0, 1) << "\n";  // compilation error: T=int or T=double?
}
