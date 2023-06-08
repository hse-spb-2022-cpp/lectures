#include <tuple>

template<typename, typename>
struct Foo {
};

template<typename ...As, typename ...Bs>  // Ok, multiple parameter packs.
struct Foo<std::tuple<As...>, std::tuple<Bs...>> {  // Similar to template type deduction.
};

// We can "parse" types, like in boots::function_traits
template<typename> struct function_traits {};
template<typename Ret, typename ...Args>
struct function_traits<Ret(*)(Args...)> {
    static constexpr std::size_t arity = sizeof...(Args);
    using return_type = Ret;
};

static_assert(std::is_void_v<
    function_traits<void(*)(int, int, char)>::return_type
>);
static_assert(
    function_traits<void(*)(int, int, char)>::arity == 3
);
