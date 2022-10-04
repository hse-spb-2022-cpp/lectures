#/bin/bash
g++ -c main.cpp -O2 -DDEBUG -std=c++17
g++ -c print_hello.cpp -O2 -DDEBUG -std=c++17
g++ main.o print_hello.o -O2 -std=c++17 -o main-02
