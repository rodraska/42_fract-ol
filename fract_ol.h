#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx_data {
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}				t_mlx_data;

typedef struct s_rect {
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_circle {
	int x0;
	int y0;
	int	r;
	int	color;
}	t_circle;


# define M_PI		3.14159265358979323846	/* pi */
# define W 1920
# define H 1080
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define YELLOW 0x00FFFF00
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000

void    ft_square(t_data *img, int x0, int y0, int xf, int yf, int color);
void    ft_circle(t_data *img, int rf, int x0, int y0, int color);
void    ft_circle2(t_data *img, int color);
void    ft_reta(t_data *img, float x1, float y1, float x2, float y2, int color);
void    ft_yequals2x(t_data *img);
void    ft_sin(t_data *img);
void    ft_portugal(t_data *img);
void	ft_scp(t_data *img);
void    ft_circle_gradient(t_data *img, int color);

void    render_background(t_data *img, int color);
void    render_rect(t_data *img, t_rect rect);
void    render_circle(t_data *img, t_circle circle);
void    render_circle2(t_data *img, t_circle circle);
void    render_portugal(t_data *img);

int		handle_keypress(int keysym, t_mlx_data *data);
int		handle_keyrelease(int keysym, void *data);
int		handle_no_event(void *data);
int		handle_input(int keysym, t_mlx_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int		ft_strlen(char *str);
int		add_shade(int color, float ratio);
int		get_opposite(int color);

#endif