#include <iostream>
#include <stdexcept>

struct cannot_read_int : std::runtime_error {
    cannot_read_int() : std::runtime_error("Cannot readInt from std::cin") {}
};

int readInt() {
    int x;
    std::cin >> x;
    if (!std::cin) {
        throw cannot_read_int();
    }
    return x;
}

struct Point {
    int x = 0, y = 0;
    void read() {
        x = readInt();
        y = readInt();
    }
};

int main() {
    Point p;
    for (;;) {
        try {
            p.read();
        } catch (const std::exception &e) {
            std::cout << e.what() << "\n";
            break;
        }
    }
    std::cout << "Last point is " << p.x << " " << p.y << "\n";
}
