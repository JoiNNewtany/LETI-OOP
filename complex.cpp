#include <cmath>
#include "complex.hpp"

using std::pow;

Complex::Complex()
{
    re = im = 0;
}

Complex::Complex(double r)
{
    re = r;
    im = 0;
}

Complex::Complex(double r, double i)
{
    re = r;
    im = i;
}

bool Complex::operator==(const Complex& c)
{
    return (this->re == c.re) && (this->im == c.im);
}

// ONLY for real numbers
bool Complex::operator>(const Complex& c)
{
    return this->re > c.re;
}

bool Complex::operator<(const Complex& c)
{
    return this->re < c.re;
}

Complex Complex::operator*(const double val)
{
    Complex result;
    result.re = this->re * val;
    result.im = this->im * val;
    return result;
}

Complex Complex::operator*(const Complex& c)
{
    Complex result;
    result.re = this->re * c.re - this->im * c.im;
    result.im = this->im * c.re + this->re * c.im;
    return result;
}

Complex Complex::operator/(const Complex& c)
{
    Complex result;
    result.re = ((this->re * c.re) + (this->im * c.im)) / (c.re * c.re + c.im * c.im);
    result.im = ((this->im * c.re) - (this->re * c.im)) / (c.re * c.re + c.im * c.im);
    return result;
}

Complex Complex::operator+(const Complex& c)
{
    Complex result;
    result.re = this->re + c.re;
    result.im = this->im + c.im;
    return result;
}

Complex Complex::operator-(const Complex& c)
{
    Complex result;
    result.re = this->re - c.re;
    result.im = this->im - c.im;
    return result;
}

Complex pow(const Complex& c, double p)
{
    double phi = std::atan2(c.im, c.re);
    double mod = std::pow(abs(c), p);
    double real = std::cos(phi * p);
    double img = std::sin(phi * p);

    return Complex(mod * real, mod * img);
}

Complex nrt(const Complex& c, double p)
{
    return pow(c, 1.0 / p);
}

Complex sqrt(const Complex& c)
{
    return pow(c, 1.0 / 2);
}

double abs(const Complex &c) {
    return sqrt(c.re * c.re + c.im * c.im);
}

std::istream& operator>>(std::istream& is, Complex& c)
{
    return is >> c.re >> c.im;
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    return os << '(' << c.re << " + " << c.im << "i)";
}
