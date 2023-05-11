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
*/
struct Person {
    std::string name;
    Person(std::string name_) : name(std::move(name_)) {
        std::cout << "Person(" << name << ")\n";
    }
};
struct Employee : virtual /* !!! */ Person {
    std::string employer;
    Employee(std::string name_, std::string employer_) : Person(std::move(name_)), employer(std::move(employer_)) {}
};
struct Student : virtual /* !!! */ Person {
    std::string group;
    Student(std::string name_, std::string group_) : Person(std::move(name_)), group(std::move(group_)) {}
};
struct MagicStudent : Employee, Student {
    MagicStudent(std::string name_, std::string employer_, std::string group_)
        : Person(std::move(name_))
        , Employee("", std::move(employer_))
        , Student("", std::move(group_)) {}  // TODO: we still have to provide fake 'name', even though Person() is not really called.
};

void hi_employee(Employee &e) {
    std::cout << "Hi, " << e.name << " employed by " << e.employer << "!\n";
}

void hi_student(Student &s) {
    std::cout << "Hi, " << s.name << " from group " << s.group << "!\n";
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
