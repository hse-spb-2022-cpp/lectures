#include <iostream>

int main() {
    std::cout << "C++ " << __cplusplus << "\n";

    // Intel x86-64 or Apple Silicon
#if defined(__x86_64__) || defined(_WIN64) || defined(__arm64__)
    std::cout << "64-bit\n";
#else
    std::cout << "32-bit\n";
#endif

    std::cout << "Detecting compiler... ";
#if defined(__clang__)
    std::cout << "LLVM/Apple clang " << __clang_version__ << "\n";
#elif defined(__INTEL_LLVM_COMPILER)
    std::cout << "Intel clang-based compiler: " << __INTEL_LLVM_COMPILER << " " << __VERSION__ << "\n";
#elif defined(__INTEL_COMPILER)
    std::cout << "Intel C++ Compiler Classic: " << __INTEL_COMPILER << " " << __VERSION__ << "\n";
#elif defined(__GNUC__)
    std::cout << "GNU C " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << "\n";
#endif
#ifdef _MSC_VER
    std::cout << "Microsoft Visual C++ " << _MSC_VER << "\n";
#endif

    std::cout << "Detecting standard library... ";
#ifdef __GLIBCXX__
    std::cout << "GNU libstdc++: " << __GLIBCXX__ << "\n";
#endif
#ifdef _LIBCPP_VERSION
    std::cout << "LLVM/Apple libc++: " << _LIBCPP_VERSION << "\n";
#endif
#ifdef _MSVC_STL_VERSION
    std::cout << "Microsoft STL: " << _MSVC_STL_VERSION << " at " << _MSVC_STL_UPDATE << "\n";
#endif
}
