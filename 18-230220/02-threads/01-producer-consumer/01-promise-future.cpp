#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <thread>

int main() {
    std::promise<std::string> input_promise;
    std::future<std::string> input_future = input_promise.get_future();

    std::thread producer([&]() {
        std::string input;
        std::cin >> input;
        input_promise.set_value(std::move(input));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "producer after set_value-1\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "producer after set_value-2\n";
    });

    std::thread consumer([&]() {
        std::cout << "Consumer started\n";
        std::string input = input_future.get();
        std::cout << "Consumed!\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << "Processed string: " << input << "\n";
    });

    consumer.join();
    producer.join();
}
