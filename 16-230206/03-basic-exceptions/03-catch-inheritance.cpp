#include <iostream>

struct Base {
    virtual const char *who() const {
        return "Base";
    }
};

struct Derived : Base {
    const char *who() const override {
        return "Derived";
    }
};

struct Magic {
    operator Base() { return {}; }
};

int main() {
    try {
        throw Derived();
    } catch (const Base &e) {
//    } catch (Base e) {
        std::cout << "Caught: " << e.who() << "\n";
    }

    try {
        [[maybe_unused]] const Base &b = Magic();
        throw Magic();
    } catch (const Base &e) {  // Does not work, needs ~type match or inheritance.
        std::cout << "Caught Base\n";
    }
}
