#include "../fract_ol.h"

void    render_mandelbrot(t_data *img)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    while (i < H)
    {
        j = 0;
        while (j < W)
        {
            x = -2 + i * 3 / W;
            y = 1 - y * 2 / H;
        }
    }
}

complex ft_limit(complex c, complex z, int n)
{
    printf("ola");
    if (n == 10)
        return (z);
    ft_limit(c, add(multiply(z, z), c), ++n);
    
}

int main(void)
{
    complex a = ft_limit((complex){1, 0.2}, (complex){0, 0}, 0);
    printf("%f + %fi", a.re, a.im);
    return (0);
}