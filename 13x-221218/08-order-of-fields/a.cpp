struct Base {
    int x;
    int y;

    Base() : y(10), x(y) {}  // UB, -Wreorder
};
