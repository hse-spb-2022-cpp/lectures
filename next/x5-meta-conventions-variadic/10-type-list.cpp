#include <type_traits>

// Other metaprogramming libraries, e.g. boost::function_traits
template<typename .../*Ts*/> struct tail {};
#if 0
template<typename Head, typename ...Tail>
struct tail<Head, Tail...> {
    using types = Tail...;  // parameter pack is not a type
};
#endif

// Workaround: create a helper type
template<typename...> struct type_list {};
template<typename Head, typename ...Tail>
struct tail<Head, Tail...> {
    using type = type_list<Tail...>;
};
template<typename ...Ts> using tail_t = typename tail<Ts...>::type;

// Hard to use, has to specialize for every use:
template<typename> struct type_list_to_tuple {};
template<typename ...Ts> struct type_list_to_tuple<type_list<Ts...>> {
    using type = std::tuple<Ts...>;
};
static_assert(
    std::is_same_v<
        typename type_list_to_tuple<tail_t<int, string>>::type,
        std::tuple<string>
    >
);
