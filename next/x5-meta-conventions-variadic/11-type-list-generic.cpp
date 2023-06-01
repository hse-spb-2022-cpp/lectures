#include <type_traits>

template<typename...> struct type_list {};

template<typename .../*Ts*/> struct tail {};
template<typename Head, typename ...Tail>
struct tail<Head, Tail...> {
    using type = type_list<Tail...>;
};
template<typename ...Ts> using tail_t = typename tail<Ts...>::type;

// More generic solution
// Base case, unused
template<template<typename...> typename /*F*/, typename /*TypeList*/>
struct apply_type_list;

// Specialization
template<template<typename...> typename F, typename ...Ts>
struct apply_type_list<F, type_list<Ts...>> {
    using type = F<Ts...>;
};
static_assert(std::is_same_v<
    typename apply_type_list<tuple, type_list<int, string>>::type,
    tuple<int, string>
);
