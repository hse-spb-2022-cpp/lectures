#include <stdio.h>

enum EventType { MOUSE, KEYBOARD };

struct MouseEvent {  // ~12 bytes
    int x;
    int y;
    int button;
};

struct KeyboardEvent {  // ~8 bytes
    int key;
    int is_down;
};

// tagged union: std::variant<MouseEvent, KeyboardEvent>
// Haskell: tagged union is called "type sum", but syntax is better and safer.
// Rust: tagged union is called "enum".
struct Event {  // ~16
    EventType type;
    union AnyEvent {  // ~12 bytes, ensures proper alignment for all.
        struct MouseEvent mouse;
        struct KeyboardEvent keyboard;
    } event;
};

int main(void) {
    printf("%d\n", sizeof(struct Event));
    struct Event ev;
    ev.type = MOUSE;
    ev.event.mouse.x = 11;
    ev.event.mouse.y = 22;
    ev.event.mouse.button = 1;
    // https://stackoverflow.com/a/25672839/767632
    // Implementation-defined in C (object representation), no strict aliasing violation for unions specifically.
    // UB in C++ (accessing non-active union member + strict aliasing).
    // OK in GCC in C++:
    // https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#Type-punning
    printf("%d\n", ev.event.keyboard.key);  // UB in C++, 11 in C.
}
