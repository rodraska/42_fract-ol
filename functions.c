#include "fract_ol.h"

void    ft_square(t_data *img, int x0, int y0, int xf, int yf, int color)
{
    int x;
    int y;

    x = x0;
    while (++x < xf)
    {
        y = y0;
        while (++y < yf)
            my_mlx_pixel_put(img, x, y, color);
    }
}

void    ft_circle(t_data *img, int rf, int x0, int y0, int color)
{
    int r;
    float t;

    r = 0;
    while (++r < rf)
    {
        t = 0.01;
        while (t < 2 * M_PI)
        {
            my_mlx_pixel_put(img, x0 + r * cos(t), y0 + r * sin(t), color);
            t += 0.01;
        }
    }
}

void    ft_circle2(t_data *img)
{
    double  x;
    double  y;
    double  r;

    x = -1;
    y = -1;
    r = 200;
    while (sqrt(pow(++x, 2) + pow(y, 2)) < r)
    {
        while (sqrt(pow(x, 2) + pow(++y, 2)) < r)
        {
            my_mlx_pixel_put(img, W / 2 + x, H / 2 + y, 0x0033FFCC);
            my_mlx_pixel_put(img, W / 2 - x, H / 2 - y, 0x0033FFCC);
            my_mlx_pixel_put(img, W / 2 + x, H / 2 - y, 0x0033FFCC);
            my_mlx_pixel_put(img, W / 2 - x, H / 2 + y, 0x0033FFCC);
        }
        y = -1;
    }
}

void    ft_reta(t_data *img, float x1, float y1, float x2, float y2, int color)
{
    float   x;
    float   y;
    float   m;
    float   n;

    if (x1 == x2)
    {
        while (y1 != y2)
        {
            my_mlx_pixel_put(img, x1, y1, color);
            if (y1 < y2)
                y1++;
            else
                y1--;
        }
        return ;
    }
    else
        m = (y2 - y1) / (x2 - x1);
    n = y1 - m * x1;
    x = x1;
    y = y1;
    while (x != x2)
    { 
        my_mlx_pixel_put(img, x, y, color);
        if (x < x2)
            x ++;
        else
            x--;
        y = m * x + n;
    }
    
}

void    ft_yequals2x(t_data *img)
{
    double  x;

    x = -1;
    while (++x < 250)
    {
        my_mlx_pixel_put(img, W / 2 + x, H / 2 + 2 * (-x), 0x0033FFCC);
        my_mlx_pixel_put(img, W / 2 - x, H / 2 + 2 * (x), 0x0033FFCC);
    }
}

void    ft_sin(t_data *img)
{
    double  x;

    x = -1;
    while (++x < W / 2)
    {
        my_mlx_pixel_put(img, W / 2 + x, H / 2 + 120 * sin(x/25), 0x0033FFCC);
        my_mlx_pixel_put(img, W / 2 - x, H / 2 - 120 * sin(x/25), 0x0033FFCC);
    }
        
}

void    ft_portugal(t_data *img)
{
    ft_square(img, 0, 0, 750, 1080, 0x00339900);
    ft_square(img, 750, 0, 1920, 1080, 0x00FF3300);
    ft_circle(img, 220, 750, H / 2, 0x00FFFF00);
}

void    ft_scp(t_data *img)
{
    ft_reta(img, W / 4 - 180, 3 * H / 4, W / 4 + 180, 3 * H / 4, 0x0066FF33);
    ft_reta(img, W / 4 + 180, 3 * H / 4, W / 4 + 180, H / 2, 0x0066FF33);
    ft_reta(img, W / 4 + 180, H / 2, W / 4 - 180, H /2, 0x0066FF33);
    ft_reta(img, W / 4 - 180, H /2, W / 4 - 180, H / 4, 0x0066FF33);
    ft_reta(img, W / 4 - 180, H / 4, W / 4 + 180, H / 4, 0x0066FF33);

    ft_reta(img, W / 2 - 180, 3 * H / 4, W / 2 + 180, 3 * H / 4, 0x0066FF33);
    ft_reta(img, W / 2 - 180, 3 * H / 4, W / 2 - 180, H / 4, 0x0066FF33);
    ft_reta(img, W / 2 - 180, H / 4, W / 2 + 180, H / 4, 0x0066FF33);

    ft_reta(img, 3 * W / 4 - 180, 3 * H / 4, 3 * W / 4 - 180, H / 4, 0x0066FF33);
    ft_reta(img, 3 * W / 4 - 180, H / 4, 3 * W / 4 + 180, H / 4, 0x0066FF33);
    ft_reta(img, 3 * W / 4 + 180, H / 4, 3 * W / 4 + 180, H / 2, 0x0066FF33);
    ft_reta(img, 3 * W / 4 + 180, H / 2, 3 * W / 4 - 180, H / 2, 0x0066FF33);
}