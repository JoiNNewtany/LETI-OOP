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

Complex Complex::operator*(const double val)
{
    Complex result;
    result.re = this->re * val;
    result.im = this->re * val;
    return result;
}

Complex Complex::operator*(const Complex& c)
{
    Complex result;
    result.re = this->re * c.re - this->im * c.im;
    result.im = this->re * c.im + this->im * c.re;
    return result;
}

Complex Complex::reciprocal(const Complex& c)
{
    Complex result;
    result.set_re(c.get_re_c() / (pow(c.get_re_c(), 2) + pow(c.get_im_c(), 2)));
    result.set_im(c.get_im_c() / (pow(c.get_re_c(), 2) + pow(c.get_im_c(), 2)));
    return result;
}

Complex Complex::operator/(const Complex& c)
{
    if (c.im == 0)
        return Complex(this->re / c.re);

    return (*this) * reciprocal(c);
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

Complex sqrt(Complex c)
{
    // Find complex roots using de Moivre's theorem
    Complex result;
    double r = sqrt(pow(c.get_re(), 2) + pow(c.get_im(), 2));
    double t = std::atan2(c.get_im(), c.get_re());
    result.set_re(r * std::cos(t));
    result.set_im(std::sin(t));
    return result;
}

std::istream& operator>>(std::istream& is, Complex& c)
{
    return is >> c.re >> c.im;
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    return os << '(' << c.re << " + " << c.im << "i)";
}
