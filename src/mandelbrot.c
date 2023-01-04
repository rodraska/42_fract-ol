#include "../fract_ol.h"

void    render_mandelbrot(t_data *img)
{
    double  i;
    double  j;
    double  x;
    double  y;
    int     n;

    i = -1;
    n = -1;
    while (++i < W)
    {
        j = -1;
        while (++j < H)
        {
            x = -2 + i * 3 / W;
            y = 1 - j * 2 / H;
            //printf(" x: %f,y: %f,n: %d", x, y, ++n);
            if (ft_limit((complex){x, y}, (complex){0, 0}, 0) <= 2)
                my_mlx_pixel_put(img, i, j, BLACK);
        }
    }
}

double  ft_limit(complex c, complex z, int n)
{
    //printf("%d: ", n);
    //printf("%f + %fi\n", z.re, z.im);
    if (n == 1000 || module(z) > 2)
        return (module(z));
    ft_limit(c, add(multiply(z, z), c), ++n);
}

/* int main(void)
{
    complex a = add(multiply((complex){1, 3}, (complex){1, 3}), (complex){1, 1});
    printf("%f + %fi", a.re, a.im);

    double  a = ft_limit((complex){-1, 0}, (complex){0, 0}, 0);
    printf("%f ", a);

    render_mandelbrot();
    
    return (0);
} */