#include <fstream>
#include <iostream>
#include <string>

void check_file(const std::string &filename) {
    std::ifstream f(filename);
    std::cout << "Reading from " << filename << "\n";
    // Easy to forget to check.
    std::cout << "    is_open: " << f.is_open() << "\n";
    for (;;) {
        // https://en.cppreference.com/w/cpp/io/ios_base/iostate
        // State, not result of operation
        std::cout << "    status: " << f.rdstate() << "; "
                  << std::ios_base::badbit << " "  // irrecoverable error
                  << std::ios_base::failbit << " "  // format/extract error
                  << std::ios_base::eofbit << "\n";  // EOF reached
        if (!f) {
            break;
        }
        int x = -239;
        // Careful handling is actually required: https://en.cppreference.com/w/cpp/named_req/FormattedInputFunction
        f >> x;
        std::cout << "    x = " << x;
    }
}

int main() {
    check_file("numbers-01-simple.in");
    check_file("numbers-02-immediate-eof.in");
    check_file("does-not-exist.in");
}
