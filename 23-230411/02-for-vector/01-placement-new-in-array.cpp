#include <iostream>
#include <memory>
#include <string>

struct Person {
    std::string first_name, last_name;

    Person() : first_name(10'000, 'x') {
        std::cout << "Person created\n";
    }
};

int main() {
    alignas(alignof(Person)) char memory[sizeof(Person) * 4];  // Remember about proper alignment!

    Person *people = reinterpret_cast<Person*>(memory);
    Person *a = new (people) Person();
    Person *b = new (people + 1) Person();
    Person *c = new (people + 2) Person();
    // Person *d = new (people + 3) Person();  // ok, but do not want right now
    std::cout << static_cast<void*>(memory) << " " << a << " " << b << " " << c << std::endl;
    std::cout << a->first_name.size() << std::endl;

    // Order is not important, but I prefer to mimic automatic storage duration.
    c->~Person();
    b->~Person();
    a->~Person();
}
