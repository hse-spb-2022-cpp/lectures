#include <iostream>
#include "field.hpp"

/*namespace field {
struct Field {
    int width, height;

    int area() const;
};
}  // namespace field*/

namespace cli_view {
void show_field(const field::Field &f) {
    std::cout << f.width << "x" << f.height << "\n";
}
}  // namespace cli_view
