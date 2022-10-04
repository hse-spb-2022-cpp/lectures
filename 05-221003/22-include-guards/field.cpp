#include "field.hpp"

namespace field {
int Field::area() const {
    return width * height;
}

Field create_field(int width, int height) {
    return {width, height};
}
}  // namespace field
