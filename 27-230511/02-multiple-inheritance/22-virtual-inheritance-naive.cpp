#include <string>
#include <iostream>

/*
Class diagram:

      Person
       ^  ^
      /    \
     /      \
 Employee Student
    ^        ^
     \      /
      \    /
   MagicStudent

Proposed layout (careful: in reality Person is in the end):
+-----------------------------------------------------------------------------+
| +--------+  +------------------------------+  +---------------------------+ |
| | Person |  | +---------------+            |  | +---------------+         | |
| | +name  |  | | PersonVirtual |            |  | | PersonVirtual |         | |
| +--------+  | | +person       |            |  | | +person       |         | |
|             | +---------------+            |  | +---------------+         | |
|             | EmployeeWithVirtual          |  | StudentWithVirtual        | |
|             |                    +employer |  |                    +group | |
|             +------------------------------+  +---------------------------+ |
| MagicStudent                                                                |
+-----------------------------------------------------------------------------+
or:
+-------------------------------------------+
| +--------+  +---------------------------+ |
| | Person |  | +---------------+         | |
| | +name  |  | | PersonVirtual |         | |
| +--------+  | | +person       |         | |
|             | +---------------+         | |
|             | StudentWithVirtual        | |
|             |                    +group | |
|             +---------------------------+ |
| Student                                   |
+-------------------------------------------+
*/

struct Person {
    std::string name;
    Person(std::string name_) : name(std::move(name_)) {}
};
struct PersonVirtual {
    Person *person;
    PersonVirtual(Person *person_) : person(person_) {}
};
struct EmployeeWithVirtual : PersonVirtual {
    std::string employer;
    EmployeeWithVirtual(Person *person_, std::string employer_) : PersonVirtual(person_), employer(std::move(employer_)) {}
};
struct StudentWithVirtual : PersonVirtual {
    std::string group;
    StudentWithVirtual(Person *person_, std::string group_) : PersonVirtual(person_), group(std::move(group_)) {}
};

struct MagicStudent : Person, EmployeeWithVirtual, StudentWithVirtual {
    MagicStudent(std::string name_, std::string employer_, std::string group_)
        : Person(std::move(name_))
        , EmployeeWithVirtual(this, std::move(employer_))
        , StudentWithVirtual(this, std::move(group_)) {
    }
};

struct Student : Person, StudentWithVirtual {
    Student(std::string name_, std::string group_)
        : Person(std::move(name_))
        , StudentWithVirtual(this, std::move(group_)) {
    }
};

void hi_employee(EmployeeWithVirtual &e) {
    std::cout << "Hi, " << e.person->name << " employed by " << e.employer << "!\n";
}

void hi_student(StudentWithVirtual &s) {
    std::cout << "Hi, " << s.person->name << " from group " << s.group << "!\n";
}

void hi_magic(MagicStudent &ms) {
    std::cout << "Wow, " << ms.name << " does not exist!\n";
}

int main() {
    {
        MagicStudent ms("Egor", "HSE", "MBD181");
        hi_employee(ms);
        hi_student(ms);
        hi_magic(ms);
    }
    {
        std::cout << "=====\n";
        Student s("Egor", "MBD181");
        hi_student(s);
    }
}
