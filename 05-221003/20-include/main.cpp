#include <iostream>
// Order _should not_ matter and includes _should_ be independent!
// That's why `cli_view.h` includes `field.h`
#include "field.hpp"
#include "cli_view.hpp"

int main() {
    field::Field f = field::create_field(3, 4);
    cli_view::show_field(f);
}
