#include <string>
#include <utility>

struct PersonCpp03 {
    std::string name;
    PersonCpp03(const std::string &name_) : name(name_) {}  // 1 copy
};

struct PersonCpp11 {
    std::string name;
    PersonCpp11(std::string name_) : name(std::move(name_)) {}  // 1 initialization name_ + 1 move + 1 destruct of empty
    void say(const std::string &message) {  // better than `std::string message`
        std::cout << name << " says " << message << "\n";
    }
};

std::string create_name() {
    std::string s = "hello world";
    return s;  // no std::move needed
}

int main() {
    {
        std::string x = "Egor";
        [[maybe_unused]] PersonCpp03 p1(x);  // x is copied into p1.name: 1 copy
        [[maybe_unused]] PersonCpp03 p2("Egor");  // temporary is copied: 1 init, 1 copy, 1 destruct
        [[maybe_unused]] PersonCpp03 p3(create_name());  // temporary is copied: 1 init inside create_name(), 1 copy, 1 destruct
    }
    {
        std::string x = "Egor";
        [[maybe_unused]] PersonCpp11 p1(x);  // 1 copy + 1 move + 1 destruct of empty
        [[maybe_unused]] PersonCpp11 p2("Egor");  // 1 init, 1-2 move, 1-2 destruct of empty
        [[maybe_unused]] PersonCpp11 p3(create_name());  // 1 init inside create_name(), 1-3 move, 1-3 destruct of empty
    }
}
