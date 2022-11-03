#include <cmath>
#include <string>
#include "polynomial.hpp"

Polynomial::Polynomial(number a, number b, number c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

int Polynomial::findRoots(number (&result)[2])
{
    // Find discriminant
    number d = (b * b) - 4 * a * c;

    if (d > 0) {
        // Two real roots

        result[0] = (-b + std::sqrt(d)) / (2 * a);
        result[1] = (-b - std::sqrt(d)) / (2 * a);

        return 2;
    } else if (d == 0) {
        // One real root

        result[0] = -(b / (2 * a));

        return 1;
    } else {
        // No real roots
        return 0;
    }
}

number Polynomial::findValue(number arg)
{
    return a * (arg * arg) + b * arg + c;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p)
{
    return os << p.a << "x^2 + " << p.b << "x + " << p.c;
}
