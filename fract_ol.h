#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx_linux/mlx.h"
# include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

# define M_PI		3.14159265358979323846	/* pi */
# define W 1920
# define H 1080

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    ft_square(t_data *img, int x0, int y0, int xf, int yf, int color);
void    ft_circle(t_data *img, int rf, int x0, int y0, int color);
void    ft_circle2(t_data *img);
void    ft_reta(t_data *img, float x1, float y1, float x2, float y2, int color);
void    ft_yequals2x(t_data *img);
void    ft_sin(t_data *img);
void    ft_portugal(t_data *img);
void	ft_scp(t_data *img);

#endif