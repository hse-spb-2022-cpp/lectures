#include <iostream>
#include <tuple>

template<typename ...Ts>
void foo(Ts...) {}

template<typename ...Ts>
void bar(Ts ...vs) {
    foo(vs...);  // function call
    // Different order of evaluation:
    [[maybe_unused]] std::tuple t1(vs...);  // direct initialization
    [[maybe_unused]] std::tuple t2{vs...};  // direct list initialization
    [[maybe_unused]] int data[] = {vs...};  // array initialization
    int x = 10;
    [x, vs...]() {};  // works with captures
    [x, &vs...]() {};  // works with captures
    // [x, vs = std::move(vs)...]() {};  // no simple way to "move" parameter pack
    [x, vs = std::make_tuple(std::move(vs)...)]() {};  // only via std::tuple (it moves/copies arguments inside a tuple), may need std::apply inside.

    for (double d : data) {
        std::cout << d << "\n";
    }
}

int main() {
    bar(12, 3.4);
}
