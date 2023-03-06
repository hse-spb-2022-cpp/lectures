#include "my_templ.hpp"

void foo() {
    my_template<double>{}.foo();
    my_template<double>{}.bar();
}
