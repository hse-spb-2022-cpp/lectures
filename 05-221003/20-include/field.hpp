// Alternative: '#pragma once', not in standard, but all major compilers support it.
#ifndef FIELD_HPP_  // Include guards
#define FIELD_HPP_

namespace field {
struct Field {
    int width, height;

    int area() const;
};

Field create_field(int width, int height);
}  // namespace field

#endif  // FIELD_HPP_
