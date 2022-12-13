#pragma once

#include <ostream>
#include <cmath>
#include <string>

// Second degree polynomial
template <class number>
class Polynomial
{
public:
    Polynomial(number, number, number);
    int findRoots(number (&)[2]);
    number findValue(number);

    template <class T>
    friend std::ostream& operator<<(std::ostream&, const Polynomial<T>&);
private:
    // Term coefficients
    // Example: ax^2 + bx + c
    number a = 0, b = 0, c = 0;
};

template <class number>
Polynomial<number>::Polynomial(number a, number b, number c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

template <class number>
int Polynomial<number>::findRoots(number (&result)[2])
{
    // Find discriminant
    number d = (b * b) - a * 4 * c;

    if (d == 0) {
        // One root

        result[0] = (b / (a * 2)) * -1;

        return 1;
    } else {
        // Two roots

        result[0] = ((b * -1) + sqrt(d)) / (a * 2);
        result[1] = ((b * -1) - sqrt(d)) / (a * 2);

        return 2;
    }

    return 0;
}

template <class number>
number Polynomial<number>::findValue(number arg)
{
    return a * (arg * arg) + b * arg + c;
}

template <class number>
std::ostream& operator<<(std::ostream& os, const Polynomial<number>& p)
{
    return os << p.a << "x^2 + " << p.b << "x + " << p.c;
}
