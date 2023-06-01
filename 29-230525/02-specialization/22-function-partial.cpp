#include <iostream>
#include <vector>

// No partial specializations for functions, unlike classes.
// Can be emulated: delegate to a member of a class.
template<typename T>
struct reader;

template<typename T>
T read() {
    return reader<T>::read();
}

template<typename T>
struct reader {
    static T read() {
        T res;
        std::cin >> res;
        return res;
    }
};

template<typename T>
struct reader<std::vector<T>> {
    static std::vector<T> read() {
        int n;
        std::cin >> n;
        std::vector<T> res(n);
        for (auto &v : res) {
            // v = reader<T>::read();  // OK
            // v = read<T>();  // Does not compile: thinks it's `reader::read`, not `::read`
            v = ::read<T>();
        }
        return res;
    }
};

int main() {
    std::cout << read<int>() << "\n";
    auto vec = read<std::vector<double>>();
    std::cout << vec.size() << "\n";
    std::cout << vec[0] << "\n";
}
