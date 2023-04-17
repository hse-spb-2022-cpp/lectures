#include <cstddef>
#include <iostream>
#include <memory>
#include <string>

struct alignas(0x10000) Person {  // Overaligned type
    std::string first_name, last_name;

    Person() : first_name(10'000, 'x') {
        std::cout << "Person created\n";
    }
};

int main() {
    char *memory = new char[sizeof(Person) * 4];
    std::cout << alignof(std::max_align_t) << "\n";
    // Alignment is only up to `max_align_t`: https://stackoverflow.com/q/10587879/767632

    Person *people = reinterpret_cast<Person*>(memory);
    Person *a = new (people) Person();
    Person *b = new (people + 1) Person();
    Person *c = new (people + 2) Person();
    std::cout << static_cast<void*>(memory) << " " << a << " " << b << " " << c << std::endl;
    std::cout << a->first_name.size() << std::endl;

    c->~Person();
    b->~Person();
    a->~Person();

    delete[] memory;
}
