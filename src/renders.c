#include "../fract_ol.h"

void    render_background(t_data *img, int color)
{
    int i;
    int j;

    i = 0;
    while (i < H)
    {
        j = 0;
        while (j < W)
            my_mlx_pixel_put(img, j++, i, color);
        ++i;
    }
}

void    render_rect(t_data *img, t_rect rect)
{
    int i;
    int j;

    check_offset(&rect);
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width && in_bounds(j, i))
        {
            my_mlx_pixel_put(img, j++, i, rect.color);
        }
        i++;
    }
}

void    render_circle(t_data *img, t_circle circle)
{
    double  r;
    double  t;

    r = -1;
    while (++r < circle.r)
    {
        t = 0.00;
        while (t < 2 * M_PI)
        {
            if (in_bounds(circle.x0 + r * cos(t), circle.y0 + r * sin(t)))
                my_mlx_pixel_put(img, circle.x0 + r * cos(t), circle.y0 + r * sin(t), circle.color);
            t += 0.001;
        }
    }
}

void    render_circle2(t_data *img, t_circle circle)
{
    double  x;
    double  y;

    x = -1;
    y = -1;
    while (sqrt(pow(++x, 2) + pow(y, 2)) < circle.r)
    {
        while (sqrt(pow(x, 2) + pow(++y, 2)) < circle.r)
        {
            my_mlx_pixel_put(img, circle.x0 + x, circle.y0 + y, circle.color);
            my_mlx_pixel_put(img, circle.x0 - x, circle.y0 - y, circle.color);
            my_mlx_pixel_put(img, circle.x0 + x, circle.y0 - y, circle.color);
            my_mlx_pixel_put(img, circle.x0 - x, circle.y0 + y, circle.color);
        }
        y = -1;
    }
}

void    render_quad(t_data *img, t_rect rect)
{
    int x;
    int y;

    x = -1;
    y = -1;
    while (++x < rect.width)
    {
        while (++y < rect.height)
        {
            if (in_bounds(rect.x + x, rect.y + y))
                my_mlx_pixel_put(img, rect.x + x, rect.y + y, rect.color);
            if (in_bounds(rect.x - x, rect.y - y))
                my_mlx_pixel_put(img, rect.x - x, rect.y - y, rect.color);
            if (in_bounds(rect.x + x, rect.y - y))
                my_mlx_pixel_put(img, rect.x + x, rect.y - y, rect.color);
            if (in_bounds(rect.x - x, rect.y + y))
                my_mlx_pixel_put(img, rect.x - x, rect.y + y, rect.color);
        }    
        y = -1;
    }
}

void    render_portugal(t_data *img)
{
    render_rect(img, (t_rect){0, 0, 750, 1080, GREEN});
    render_rect(img, (t_rect){750, 0, 1920 - 750, 1080, RED});
    render_circle(img, (t_circle){750, H / 2, 220, YELLOW});
}
