#include <cstddef>
#include <string>
#include <iomanip>
#include <iostream>

struct Person { std::string name; };
struct Employee : virtual Person { std::string employer; };
struct Student : virtual Person { std::string group; };
struct MagicStudent : Employee, Student {};

/*
Somewhat real layout (although not guaranteed)
0                8            40             48       80           112
+----------------------------------------------------------------+
| +------------------------+  +---------------------+ +--------+ |
| | +---------+            |  | +---------+         | | Person | |
| | | PersonV |            |  | | PersonV |         | | +name  | |
| | | +person |            |  | | +person |         | +--------+ |
| | +---------+            |  | +---------+         |            |
| | Employee'              |  | Student'            |            |
| |              +employer |  |              +group |            |
| +------------------------+  +---------------------+            |
| MagicStudent                                                   |
+----------------------------------------------------------------+
or:
0                8           40           72
+---------------------------------------+
| +------------------------+ +--------+ |
| | +---------+            | | Person | |
| | | PersonV |            | | +name  | |
| | | +person |            | +--------+ |
| | +---------+            |            |
| | Employee'              |            |
| |              +employer |            |
| +------------------------+            |
| Employee                              |
+---------------------------------------+

NOTE: 'person' pointers may be relative, not absolute.
*/

void print(const char *data, int size) {
    std::cout << "    .0 .1 .2 .3 .4 .5 .6 .7  .8 .9 .a .b .c .d .e .f\n";
    for (int start = 0; start < size; start += 16) {
        std::cout << std::hex << (start / 16) << ". ";
        for (int i = 0; i < 16 && start + i < size; i++) {
            if (i == 8) {
                std::cout << ' ';
            }
            std::cout << ' ' << std::setfill('0') << std::setw(2) << std::hex << (data[start + i] & 0xFF);
        }
        std::cout << '\n';
    }
}

template<typename T>
void print_bytes(const T &v) {
    print(reinterpret_cast<const char *>(&v), sizeof v);
}

int main() {
    std::cout << "sizeof(string) = " << sizeof(std::string) << "\n";
    std::cout << "sizeof(Person) = " << sizeof(Person) << "\n";
    {
        std::cout << "MagicStudent layout\n";
        alignas(0x100) MagicStudent ms;
        Employee &e = ms;
        Student &s = ms;
        Person &p = ms;
        std::cout << "    sizeof = " << sizeof(ms) << "\n";
        std::cout << "    this      = " << &ms << "\n";
        std::cout << "    Employee  = " << &e << "\n";
        std::cout << "    .employer = " << &ms.employer << "\n";
        std::cout << "    Student   = " << &s << "\n";
        std::cout << "    .group    = " << &ms.group << "\n";
        std::cout << "    Person    = " << &p << "\n";
        std::cout << "    .name     = " << &ms.name << "\n";

        print_bytes(ms);
    }

    {
        std::cout << "Employee layout\n";
        alignas(0x100) Employee e;
        Person &p = e;
        std::cout << "    sizeof = " << sizeof(e) << "\n";
        std::cout << "    this      = " << &e << "\n";
        std::cout << "    .employer = " << &e.employer << "\n";
        std::cout << "    Person    = " << &p << "\n";
        std::cout << "    .name     = " << &e.name << "\n";

        print_bytes(e);
    }
}
