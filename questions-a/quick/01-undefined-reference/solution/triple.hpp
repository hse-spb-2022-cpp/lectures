#ifndef TRIPLE_HPP_
#define TRIPLE_HPP_

struct Triple {
    int a, b, c;

    int sum() const {
        return a + b + c;
    }
    void print() const;
};

#endif  // TRIPLE_HPP_
