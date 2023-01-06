#include "../fract_ol.h"

complex square(complex z)
{
    complex z2;

    z2.re = pow(z.re, 2) - pow(z.im, 2);
    z2.im = 2 * z.re * z.im;
    return (z2);
}

complex add(complex a, complex b)
{
    complex c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return (c);
}

float   module(complex a)
{
    return (sqrt(pow(a.re, 2) + pow(a.im, 2)));
}