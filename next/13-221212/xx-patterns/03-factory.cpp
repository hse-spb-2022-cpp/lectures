#include <iostream>
#include <memory>
#include <random>
#include <string>

// Kind of
// https://ru.wikipedia.org/wiki/%D0%90%D0%B1%D1%81%D1%82%D1%80%D0%B0%D0%BA%D1%82%D0%BD%D0%B0%D1%8F_%D1%84%D0%B0%D0%B1%D1%80%D0%B8%D0%BA%D0%B0_(%D1%88%D0%B0%D0%B1%D0%BB%D0%BE%D0%BD_%D0%BF%D1%80%D0%BE%D0%B5%D0%BA%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F)
struct StringFactory {
    StringFactory() = default;
    StringFactory(const StringFactory &) = delete;
    StringFactory(StringFactory &&) = delete;
    StringFactory &operator=(const StringFactory &) = delete;
    StringFactory &operator=(StringFactory &&) = delete;
    virtual ~StringFactory() {
    }

    virtual std::string read_string() = 0;
};

struct CinFactory : StringFactory {
    std::string read_string() override {
        std::string s;
        std::cin >> s;
        return s;
    }
};

struct ConstFactory : StringFactory {
    ConstFactory(std::string value_) : m_value(std::move(value_)) {
    }

    std::string read_string() override {
        return m_value;
    }

private:
    std::string m_value;
};

int main() {
    std::default_random_engine eng(std::random_device{}());
    std::bernoulli_distribution distrib;

    std::unique_ptr<StringFactory> reader;
    if (distrib(eng)) {
        reader = std::make_unique<CinFactory>();
    } else {
        reader = std::make_unique<ConstFactory>("example");
    }

    // independent part
    std::string data = reader->read_string();
    std::cout << "read: " << data << "\n";
}
