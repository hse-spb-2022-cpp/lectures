#include <cstring>
#include <iostream>
#include <fstream>

struct Person {
    char first_name[31]{};
    char last_name[31]{};
};

int main() {
    Person p;
    std::strcpy(p.first_name, "Konstantin");
    std::strcpy(p.first_name, "Ivan");
    std::strcpy(p.last_name, "Ivanov");

    {
        std::ofstream f("01.bin", std::ios::binary);
        f.write(reinterpret_cast<const char*>(&p), sizeof p);
    }
}
