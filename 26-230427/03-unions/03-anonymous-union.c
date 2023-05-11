#include <stdio.h>

enum EventType { MOUSE, KEYBOARD };

// tagged union: std::variant<MouseEvent, KeyboardEvent>
struct Event {  // 16
    EventType type;
    union {
        struct {
            int x;
            int y;
            int button;
        } mouse;
        struct {
            int key;
            int is_down;
        } keyboard;
    } /* event */;  // Anonymous/unnamed union member, C11 and C++98
    // Do not confuse with `union { ... } event;`
};

int main(void) {
    printf("%d\n", sizeof(struct Event));
    struct Event ev;
    ev.type = MOUSE;
    ev /*.event*/.mouse.x = 11;
    ev /*.event*/.mouse.y = 22;
    ev /*.event*/.mouse.button = 1;
}
