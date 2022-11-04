#pragma once

#include <iostream>
//#include <cmath>

class Complex
{
public:
    Complex();
    Complex(double);
    Complex(double, double);

    double get_re() { return re; }
    double get_re_c() const { return re; }
    void set_re(double r) { re = r; }
    double get_im() { return im; }
    double get_im_c() const { return im; }
    void set_im(double i) { im = i; }

    static Complex reciprocal(const Complex&);

    bool operator==(const Complex&);
    bool operator>(const Complex&);
    Complex operator*(const double);
    Complex operator*(const Complex&);
    Complex operator/(const Complex&);
    Complex operator+(const Complex&);
    Complex operator-(const Complex&);

    friend Complex sqrt(Complex);
    friend std::istream& operator>>(std::istream&, Complex&);
    friend std::ostream& operator<<(std::ostream&, const Complex&);
private:
    double re, im;
};

