#include <iostream>
#include <memory>
#include <string>

struct Person {
    const int id;
    std::string &name;

    Person(int id_, std::string &name_) : id(id_), name(name_) {
        std::cout << "Person created\n";
    }
};

int main() {
    Person *buf = std::allocator<Person>().allocate(4);

    // https://wg21.link/P0532R0
    // More recent: https://stackoverflow.com/a/70419156/767632
    // https://miyuki.github.io/2016/10/21/std-launder.html
    // One can also try changing type of the object: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=86908

    std::string name1 = "Alex", name2 = "Sasha";

    Person *a = new (buf) Person(10, name1);
    std::cout << a->id << std::endl;  // 10
    std::cout << a->name << std::endl;  // Alex
    a->~Person();

    Person *b = new (buf) Person(11, name2);
    std::cout << std::endl;
    std::cout << a << " " << b << std::endl;
    std::cout << b->id << std::endl;  // 11
    std::cout << b->name << std::endl;  // Sasha
    std::cout << std::endl;
    std::cout << a->id << std::endl;  // 11? UB? I dunno :(
    std::cout << buf[0].id << std::endl;  // 11? UB? I dunno :(
    std::cout << std::launder(&buf[0])->id << std::endl;  // 11. Not UB.
    b->~Person();

    // We do NOT try to deeply understand or use `std::launder`.

    std::allocator<Person>().deallocate(buf, 4);
}
