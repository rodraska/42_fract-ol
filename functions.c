#include "fract_ol.h"

void    ft_square(t_data *img)
{
    int i;
    int k;

    i = -1;
    while (++i < 100)
    {
        k = -1;
        while (++k < 100)
            my_mlx_pixel_put(img, i, k, 0x0033FFCC);
    }
}