int main() {
#ifdef __GNUC__  // Everything is very compiler-specific, see doctest.h for an example
    // `#pragma` is a compiler command, not preprocessor
    #pragma GCC diagnostic push  // save current warnings state to a stack
    #pragma GCC diagnostic ignored "-Wunused-variable"
#endif
    /* [[maybe_unused]] */ int x = 10;
#ifdef __GNUC__
    #pragma GCC diagnostic pop  // restore warnings state
#endif
}
