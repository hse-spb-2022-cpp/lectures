1. Compile `main.cpp` at `../` and copy `../main.o` to `main.o`.
2. Compile `print_hello.cpp` at `../` and copy `../print_hello.o` to `print_hello_1.o`.
3. Change `print_hello.cpp`, recompile it and copy the resulting object file to `print_hello_2.o`.
4. Link `main.o` with `print_hello_1.o` and run, see result 1.
5. Link `main.o` with `print_hello_2.o` and run, see result 2.
