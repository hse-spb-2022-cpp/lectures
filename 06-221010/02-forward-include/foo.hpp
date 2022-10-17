#ifndef FOO_HPP_
#define FOO_HPP_

#include "foo_fwd.hpp"

#include <vector>
// #include "bar.hpp"
#include "bar_fwd.hpp"

struct Foo {
    std::vector<Bar> bs;

    void doit();
    friend void foo_friend();
};

#endif  // FOO_HPP_
