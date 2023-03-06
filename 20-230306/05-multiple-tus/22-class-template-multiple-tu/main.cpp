#include "my_templ.hpp"

void foo();

int main() {
    my_template<int>{}.foo();
    my_template<int>{}.bar();
    foo();
}
