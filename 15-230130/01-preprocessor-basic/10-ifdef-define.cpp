#include <iostream>

// CMakeLists.txt: target_compile_definitions(main PUBLIC -DSOME_VAR)
// g++ -DSOME_VAR
#define SOME_VAR

#define VALUE 123

int main() {
    #ifdef SOME_VAR
    std::cout << "SOME_VAR was defined\n";
    #else
    std::cout << "SOME_VAR was not defined\n";
    #endif

    std::cout << VALUE << "\n";
    // std::cout << SOME_VAR << "\n";  // SOME_VAR is replaced with nothing

    #if defined(SOME_VAR) && 1 >= 2 && VALUE == 120 + 3
    std::cout << "x\n";
    #endif

    // There are "predefined macros", see https://stackoverflow.com/a/2224357
    #ifdef __cplusplus
    std::cout << "We are C++\n";
    #else
    std::cout << "We are not C++???\n";
    // Preprocessor warning/error commands: https://en.cppreference.com/w/cpp/preprocessor/error
    // #error Compiling with C is not supported  // Supported
    // #warning Compiling with C is badly supported  // Supported, official standard since C++23
    #endif

    #if __cplusplus >= 201700L
    std::cout << "C++17\n";
    #elif __cplusplus >= 201400L  // no #else #if
    std::cout << "C++14\n";
    #endif
}
