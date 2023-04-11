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
    std::allocator<Person> alloc;
    Person *people = alloc.allocate(4);  // Already aligned and of correct type: https://stackoverflow.com/a/46400243/767632

    Person *a = new (people) Person();
    Person *b = new (people + 1) Person();
    Person *c = new (people + 2) Person();
    std::cout << static_cast<void*>(people) << " " << a << " " << b << " " << c << std::endl;
    std::cout << a->first_name.size() << std::endl;

    c->~Person();
    b->~Person();
    a->~Person();

    alloc.deallocate(people, 4);
}
