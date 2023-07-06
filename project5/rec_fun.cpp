#include "rec_fun.h"

void binary_print(std::ostream &outs, unsigned int n) {
    if (n < 2) {
        outs << (n & 1);
        return;
    }

    binary_print(outs, n >> 1);
    outs << (n & 1);
}

void triangle(std::ostream &outs, unsigned int m, unsigned int n) {
    for (unsigned int i = 0; i < m; ++i) {
        outs << '*';
    }
    outs << std::endl;

    if (m < n) {
        triangle(outs, m + 1, n);
    }

    for (unsigned int i = 0; i < m; ++i) {
        outs << '*';
    }
    outs << std::endl;
}

double power(double x, int n) {
    if (n == 0) {
        return 1;
    }

    auto val = power(x, n >> 1);

    if (n & 1) {
        return val * val * x;
    } else {
        return val * val;
    }
}

void indented_sentences_helper(std::size_t m, std::size_t n, std::size_t indent) {
    for (std::size_t i = 0; i < indent; ++i) {
        std::cout << ' ';
    }
    std::cout << "This was written by calling number " << m << '.' << std::endl;

    if (m < n) {
        indented_sentences_helper(m + 1, n, indent + 1);
    }

    for (std::size_t i = 0; i < indent; ++i) {
        std::cout << ' ';
    }
    std::cout << "This was ALSO written by calling number " << m << '.' << std::endl;
}

void indented_sentences(std::size_t m, std::size_t n) {
    indented_sentences_helper(m, n, 0);
}
