#include "../fract_ol.h"

complex add(complex a, complex b)
{
    complex c;

    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return (c);
}

complex subtract(complex a, complex b)
{
    complex c;

    c.re = a.re - b.re;
    c.im = a.im - b.im;
    return (c);
}

complex multiply(complex a, complex b)
{
    complex c;

    c.re = a.re * b.re - a.im * b.im;
    c.im = a.re * b.im + a.im * b.re;
    return (c);
}

complex divide(complex a, complex b)
{
    complex c;
    double denom;

    denom = b.re * b.re + b.im * b.im;
    c.re = (a.re * b.re + a.im * b.im) / denom;
    c.im = (a.im * b.re - a.re * b.im) / denom;
    return (c);
}

double module(complex a)
{
    return (sqrt(a.re * a.re + a.im * a.im));
}