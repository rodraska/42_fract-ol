/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:47:59 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/11 16:03:22 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	render_mandelbrot(t_data *img)
{
	int	i;
	int	j;
	int	lim;

	i = -1;
	while (++i < W)
	{
		j = -1;
		while (++j < H)
		{
			lim = ft_limit((t_complex){coord(i, 'x', img), \
			coord(j, 'y', img)}, (t_complex){0, 0}, img);
			if (lim == img->seed * 2000)
				my_mlx_pixel_put(img, i, j, BLACK);
			else
				my_mlx_pixel_put(img, i, j, palette(lim));
		}
	}
}

float	coord(int c, char type, t_data *img)
{
	float	k;

	if (type == 'x')
		k = -2 / img->scale - img->offset_x + c * 3 / (W * img->scale);
	else
		k = 1 / img->scale + img->offset_y - c * 2 / (H * img->scale);
	return (k);
}

int	ft_limit(t_complex c, t_complex z, t_data *img)
{
	int		n;
	float	re;
	float	im;

	n = 0;
	while (n < img->seed * 2000)
	{
		re = pow(z.re, 2) - pow(z.im, 2) + c.re;
		im = 2 * z.re * z.im + c.im;
		if (fabs(re) > 4)
			break ;
		z.re = re;
		z.im = im;
		n++;
	}
	return (n);
}

/* int ft_limit(complex c, complex z)
{
	int n;

	n = 0;
	while (n < 100)
	{
		if (module(z) > 2)
			break;
		z = add(square(z), c);
		n++;
	}
	return (n);
}
 */

int	palette(int n)
{
	int	color;

	if (n > 30)
		color = 256 * n + 16704000;
	else if (n <= 30)
		color = 6.5 * n + 60;
	return (color);
}
