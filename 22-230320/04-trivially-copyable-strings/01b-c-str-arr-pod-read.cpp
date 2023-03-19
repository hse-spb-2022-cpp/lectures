#include <cstring>
#include <iostream>
#include <fstream>

struct Person {
    char first_name[31]{};
    char last_name[31]{};
};

int main() {
    Person p;
    {
        std::ifstream f("01.bin", std::ios::binary);
        f.read(reinterpret_cast<char*>(&p), sizeof p);
    }
    std::cout << p.first_name << "\n";
    std::cout << p.last_name << "\n";
}
