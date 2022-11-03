#pragma once

#include <ostream>
#include "number.hpp"

// Second degree polynomial
class Polynomial
{
public:
    Polynomial(number, number, number);
    int findRoots(number (&)[2]);
    number findValue(number);

    friend std::ostream& operator<<(std::ostream&, const Polynomial&);
private:
    // Term coefficients
    // Example: ax^2 + bx + c
    number a = 0, b = 0, c = 0;
};
