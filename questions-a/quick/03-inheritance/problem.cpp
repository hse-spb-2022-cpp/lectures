#include <string>
#include <vector>
#include <iostream>

struct Str {
    std::string s;

    Str(std::string s_) : s(std::move(s_)) {}
    std::string to_string() const {
        return s;
    }
};

struct Int {
    int x;

    Int(int x_) : x(x_) {}
    std::string to_string() const{
        return std::to_string(x);
    }
};

int main() {
    std::vector<TODO> v{
        Str{"hello"},
        Int{10},
    };

    for (TODO x : v) {
        std::cout << x.to_string() << "\n";
    }
}
