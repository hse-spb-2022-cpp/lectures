See `05-221003\01-declare-define\04-incomplete-type.cpp `

struct Bar;
std::unique_ptr<Bar> x;  // should work, but not necessarily destruct
