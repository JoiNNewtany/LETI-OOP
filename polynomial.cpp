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
    if (a == 0)
        return -1;

    // Find discriminant
    number d = (b * b) - a * 4 * c;

    if (d > 0) {
        // Two real roots

        result[0] = ((b * -1) + sqrt(d)) / (a * 2);
        result[1] = ((b * -1) - sqrt(d)) / (a * 2);

        return 2;
    } else if (d == 0) {
        // One real root

        result[0] = (b / (a * 2)) * -1;

        return 1;
    } else {
        // Two complex roots

        double real = ((b * -1) / (a * 2)).get_re();
        double imag = (sqrt(d * -1) / (a * 2)).get_re();

        result[0].set_re(real);
        result[0].set_im(imag);
        result[1].set_re(real);
        result[1].set_im(imag * -1);

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
