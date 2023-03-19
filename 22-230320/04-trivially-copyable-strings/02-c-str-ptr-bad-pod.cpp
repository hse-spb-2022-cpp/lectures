#include <cstring>
#include <iostream>
#include <fstream>

struct Person {
    const char *first_name;
    const char *last_name;
};

int main() {
    Person p;
    p.first_name = "Ivan";
    p.last_name = "Ivanov";

    {
        std::ofstream f("02.bin", std::ios::binary);
        f.write(reinterpret_cast<const char*>(&p), sizeof p);
    }
}
