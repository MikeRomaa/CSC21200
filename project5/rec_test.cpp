#include <iostream>
#include "rec_fun.h"

int main() {
    binary_print(std::cout, 8);
    std::cout << std::endl;
    binary_print(std::cout, 16);
    std::cout << std::endl;
    binary_print(std::cout, 255);
    std::cout << std::endl;
    binary_print(std::cout, 256);
    std::cout << std::endl;

    std::cout << std::endl;

    triangle(std::cout, 3, 5);
    std::cout << std::endl;
    triangle(std::cout, 2, 6);
    std::cout << std::endl;

    std::cout << power(-2, 0) << std::endl;
    std::cout << power(3, 3) << std::endl;
    std::cout << power(6, 255) << std::endl;

    std::cout << std::endl;

    indented_sentences(5, 8);
}
