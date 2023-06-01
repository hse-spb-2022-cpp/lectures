#include <cstddef>
#include <type_traits>

template<typename...> struct type_list;

// We can "parse" types, like in boots::function_trai
template<typename> struct function_traits {};
template<typename Ret, typename ...Args>
struct function_traits<Ret(*)(Args...)> {
    static constexpr std::size_t arity = sizeof...(Args);
    using return_type = Ret;
    using args = type_list<Args...>;
};

static_assert(std::is_void_v<
    function_traits<void(*)(int, int, char)>::return_type
>);

int main() {}
