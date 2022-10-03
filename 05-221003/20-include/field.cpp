#include "field.hpp"

namespace field {
/*struct Field {
    int width, height;

    int area() const;
};*/

int Field::area() const {
    return width * height;
}

Field create_field(int width, int height) {
    return {width, height};
}
}  // namespace field
