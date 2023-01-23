#include <iostream>

#define DECLARE_OPTION(T) \
struct Optional ## T { \
private: \
    T value; \
    bool exists; \
public: \
};

DECLARE_OPTION(int)
DECLARE_OPTION(std::string)

struct OptionalString {
private:
    std::string value;
    bool exists;
public:

};

int main() {
}
