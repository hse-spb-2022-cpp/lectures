using FInt = void(*)(int);
using FShort = void(*)(short);
using FNone = void(*)();

void fooi(int) {}
void foos(short) {}
void bar() {}

int main() {
    [[maybe_unused]] FInt fi = fooi;
    [[maybe_unused]] FShort fs = foos;
    [[maybe_unused]] FNone b = bar;

    // Incompatible even though 'int' and 'short' are compatible.
    // fi = fs;
    // fs = fi;

    // Cannot "ignore" arguments:
    // b = fi;
    // fi = b;

    // Technically incorrect: functions are not objects, but used in Linux a lot.
    // E.g. 'man dlsym' returns function pointer inside a shared library: https://man7.org/linux/man-pages/man3/dlopen.3.html

    // [[maybe_unused]] void *pfunc1 = static_cast<void*>(fi);
    [[maybe_unused]] void *pfunc2 = reinterpret_cast<void*>(fi);
}
