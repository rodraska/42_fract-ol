#include "../fract_ol.h"

void    render_mandelbrot(t_data *img, t_mandelbrot mandel)
{
    double  i;
    double  j;
    double  x;
    double  y;
    double  lim;
    int     n;
    int     max;

    i = -1;
    n = -1;
    max = 0;
    while (++i < W)
    {
        j = -1;
        while (++j < H)
        {
            x = mandel.x + i * 3 / mandel.width;
            y = mandel.y - j * 2 / mandel.height;
            lim = ft_limit((complex){x, y}, (complex){0, 0}, 0);
            //printf("%d %f\n", ++n, lim);
            //printf(" x: %f,y: %f,n: %d", x, y, ++n);
            if (lim == 1000)
                my_mlx_pixel_put(img, i, j, BLACK);
            else
                my_mlx_pixel_put(img, i, j, palette(lim));
        }
    }
}

int palette(double n)
{
    int color;

    if (n > 30)
        color =  256 *  n + 16704000;
    else if (n <= 30)
        color = 6.5 * n + 60;
    /* if (n > 30)
        color = RED;
    else
        color = BLUE;
    return (color); */
}

double  ft_limit(complex c, complex z, int n)
{
    //printf("%d: ", n);
    //printf("%f + %fi\n", z.re, z.im);
    if (n == 1000 || module(z) > 2)
        return ((double)n);
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