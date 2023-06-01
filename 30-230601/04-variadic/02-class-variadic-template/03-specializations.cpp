#include <tuple>

template<typename, typename>
struct Foo {
};

template<typename ...As, typename ...Bs>  // Ok, multiple parameter packs.
struct Foo<std::tuple<As...>, std::tuple<Bs...>> {  // Similar to template type deduction.
};
