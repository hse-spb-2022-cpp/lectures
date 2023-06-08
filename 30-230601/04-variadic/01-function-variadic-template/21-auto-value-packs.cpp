#include <iostream>
#include <string>

// Since C++17: each value can have an independent type.
template<auto... Ns>
constexpr auto sumAll() { return (Ns + ...); }

static_assert(sumAll<1, 2L>() == 3);

// Since C++17: each value can have an independent type.
template<auto... Fs, typename... Args>
void executeAll(Args... args) {
    (Fs(args), ...);
}

void printInt(int x) { std::cout << x << "\n"; }
void printString(std::string s) { std::cout << s << "\n"; }

struct DoublePrinter {
    int prefix;
    constexpr DoublePrinter(int prefix_) : prefix(prefix_) {}
    void operator()(double x) const {
        std::cout << prefix << " " << x << "\n";
    }
};

int main() {
    printInt(123);
    DoublePrinter{23}(5.5);

    // decltype(printInt) ~ void(*)(int)
    executeAll<printInt, printString>(10, "hello");
    // executeAll<printInt, printString, DoublePrinter{23}>(10, "hello", 4.5);  // Since C++20
}
