#include <iostream>
#include "field.hpp"
#include "cli_view.hpp"

namespace cli_view {
void show_field(const field::Field &f) {
    std::cout << f.width << "x" << f.height << "\n";
}
}  // namespace cli_view
