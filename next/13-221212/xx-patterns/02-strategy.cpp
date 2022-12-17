#include <cassert>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

// Kind of
// https://ru.wikipedia.org/wiki/%D0%A1%D1%82%D1%80%D0%B0%D1%82%D0%B5%D0%B3%D0%B8%D1%8F_(%D1%88%D0%B0%D0%B1%D0%BB%D0%BE%D0%BD_%D0%BF%D1%80%D0%BE%D0%B5%D0%BA%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F)
// Replaces std::function<void()> if we have gone full OOP.
struct AbstractTest {
    AbstractTest(std::string name_) : m_name(std::move(name_)) {
    }

    AbstractTest(const AbstractTest &) = delete;
    AbstractTest(AbstractTest &&) = delete;
    AbstractTest &operator=(const AbstractTest &) = delete;
    AbstractTest &operator=(AbstractTest &&) = delete;
    virtual ~AbstractTest() = default;

    const std::string &name() const {
        return m_name;
    }

    virtual void run() = 0;

private:
    std::string m_name;
};

struct TestSum : AbstractTest {
    TestSum() : AbstractTest("TestSum") {
    }

    void run() override {
        assert(2 + 3 == 5);
    }
};

struct TestMultiplication : AbstractTest {
    TestMultiplication() : AbstractTest("TestMultiplication") {
    }

    void run() override {
        assert(2 * 3 == 6);
    }
};

void run_simple(std::vector<std::unique_ptr<AbstractTest>> &tests) {
    for (auto &t : tests) {
        t->run();
    }
}

void run_beautiful(std::vector<std::unique_ptr<AbstractTest>> &tests) {
    for (auto &t : tests) {
        std::cout << "Running " << t->name() << "...\n";
        t->run();
    }
}

int main() {
    std::default_random_engine eng(std::random_device{}());
    std::bernoulli_distribution distrib;

    std::vector<std::unique_ptr<AbstractTest>> tests;
    if (distrib(eng)) {
        tests.emplace_back(std::make_unique<TestSum>());
    }
    if (distrib(eng)) {
        tests.emplace_back(std::make_unique<TestMultiplication>());
    }

    // independent part
    std::cout << "run_simple:\n";
    run_simple(tests);
    std::cout << "run_beautiful:\n";
    run_beautiful(tests);
}
