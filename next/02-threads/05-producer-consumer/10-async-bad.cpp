#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <thread>

int main() {
    // Может запустить код как в этом(!) потоке, так и в каком-нибудь соседнем. Без гарантий.
    std::future<std::string> input_future = std::async([]() {
        std::string input;
        std::cin >> input;
        return input;
    });
    // Похоже на команду go в языке Go, что может быть не очень хорошим стилем,
    // даже если накрутить всяких .then()/.map()/.flatMap(); это слишком низкоуровнево.
    // Например, отмену вычислений самому писать.
    // https://vorpus.org/blog/notes-on-structured-concurrency-or-go-statement-considered-harmful/
    // https://ericniebler.com/2020/11/08/structured-concurrency/

    std::thread consumer([&]() {
        std::cout << "Consumer started\n";
        std::string input = input_future.get();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << "Got string: " << input << "\n";
    });

    consumer.join();
}
