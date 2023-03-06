#include <chrono>
#include <iostream>
#include <thread>

struct Foo {
    Foo(int id) {
        std::cout << "Foo(" << id << ")@" << std::this_thread::get_id() << "\n";
    }
    ~Foo() {
        std::cout << "~Foo()@" << std::this_thread::get_id() << "\n";
    }
};

thread_local Foo foo(10);  // new kind of storage duration.

int main() {
    std::cout << "T1 &foo=" << &foo << "\n";  // Компилятор может проинициализировать лениво, но может и в момент начала потока.
    std::thread t([&]() {
        thread_local Foo bar(20);  // Инициализирует при проходе через эту строчку.
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "T2 &foo=" << &foo << "\n";  // Компилятор может проинициализировать лениво, но может и в момент начала потока.
        std::cout << "T2 &bar=" << &bar << "\n";  // Уже точно проинициализировано выше.
    });
    std::cout << "Waiting for it...\n";
    t.join();
    std::cout << "Joined\n";
    return 0;
}

/*
Зачем можно использовать: отслеживать стэк вызовов в каждом потоке.

TEST_CASE() {  // Запомнили в thread-local переменную текущий test case
    SUBCASE() {  // Запомнили текущий SUBCASE
       CHECK(....)  // Можем выводить красивое сообщение
    }
}
*/
