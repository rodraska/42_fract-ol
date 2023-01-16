/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:48:10 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/16 10:00:54 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	offset_x;
	double	offset_y;
	double	scale;
	double	julia_x;
	double	julia_y;
	double	seed;
}				t_data;

typedef struct s_mlx_data {
	void	*mlx;
	void	*mlx_win;
	int		fractal;
	t_data	img;
}				t_mlx_data;

typedef struct s_complex {
	double	re;
	double	im;
}	t_complex;

# define M_PI		3.14159265358979323846	/* pi */
# define W 900
# define H 600
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define YELLOW 0x00FFFF00
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000

int			handle_keypress(int keysym, t_mlx_data *data);
int			handle_mouse(int button, int x, int y, t_mlx_data *data);
int			handle_keyrelease(int keysym, void *data);
int			handle_no_event(void *data);
int			handle_input(int keysym, t_mlx_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_close(t_mlx_data *data);

int			in_bounds(int x, int y);
float		ft_seed(char *str);
int			is_number(char *str);
void		ft_error(void);
int			ft_input(int ac, char **av);

t_complex	square(t_complex z);
t_complex	add(t_complex a, t_complex b);
float		module(t_complex a);

void		render_mandelbrot(t_data *img);
int			ft_limit(t_complex c, t_complex z, t_data *img);
int			palette(int n);
float		coord(int c, char type, t_data *img);
void		render_julia(t_data *img);
int			julia_limit(t_complex c, t_complex z);
float		julia_coord(int c, char type, t_data *img);
int			julia_palette(int n);

#endif