#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Person {
    std::string first_name, last_name;

    Person() : first_name(10'000, 'x') {
        std::cout << "Person created\n";
    }
};

int main() {
    std::vector<Person, std::allocator<Person>> vec;
    // Does approximately the following:

    Person *people = std::allocator<Person>().allocate(4);
    Person *people2 = std::allocator<Person>().allocate(5);

    Person *a = new (people) Person();
    Person *b = new (people + 1) Person();
    Person *c = new (people + 2) Person();
    std::cout << static_cast<void*>(people) << " " << a << " " << b << " " << c << std::endl;
    std::cout << a->first_name.size() << std::endl;

    c->~Person();
    b->~Person();
    a->~Person();

    // std::allocator<Person>().deallocate(people2, 4);  // UB
    std::allocator<Person>().deallocate(people2, 5);
    std::allocator<Person>().deallocate(people, 4);

    // Better allocators with state: https://bloomberg.github.io/bde/white_papers/index.html
}
