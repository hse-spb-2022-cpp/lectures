#include <string>
#include <iostream>
#include <utility>

// Diamond problem: https://isocpp.org/wiki/faq/multiple-inheritance#mi-diamond
struct Person {
    std::string name;
    Person(std::string name_) : name(std::move(name_)) {}
};
struct Employee : Person {
    std::string employer;
    Employee(std::string name_, std::string employer_) : Person(std::move(name_)), employer(std::move(employer_)) {}
};
struct Student : Person {
    std::string group;
    Student(std::string name_, std::string group_) : Person(std::move(name_)), group(std::move(group_)) {}
};
struct MagicStudent : /*Person, */ Employee, Student {
    MagicStudent(std::string name_, std::string employer_, std::string group_)
        : Employee(name_, std::move(employer_))
        , Student(name_, std::move(group_)) {}  // FIXME: two copies of the same name
};

void hi_employee(Employee &e) {
    std::cout << "Hi, " << e.name << " employed by " << e.employer << "!\n";
}

void hi_student(Student &s) {
    std::cout << "Hi, " << s.name << " from group " << s.group << "!\n";
}

void hi_magic(MagicStudent &ms) {
    std::cout << "Wow, " << ms.name << " does not exist!\n";  // FIXME: ambiguous base
}

/*
Class diagram:

 Person   Person
    ^        ^
    |        |
 Employee Student
    ^        ^
     \      /
      \    /
   MagicStudent

But we want a single Person!

      Person
       ^  ^
      /    \
     /      \
 Employee Student
    ^        ^
     \      /
      \    /
   MagicStudent
*/

int main() {
}
