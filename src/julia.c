/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:47:42 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/11 15:01:25 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	render_julia(t_data *img)
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
			lim = julia_limit((t_complex){0 + img->seed + img->julia_x, \
			0 + img->seed + img->julia_y}, \
			(t_complex){julia_coord(i, 'x', img), julia_coord(j, 'y', img)});
			if (lim == 200)
				my_mlx_pixel_put(img, i, j, BLACK);
			else
				my_mlx_pixel_put(img, i, j, julia_palette(lim));
		}
	}
}

float	julia_coord(int c, char type, t_data *img)
{
	float	k;

	if (type == 'x')
		k = -1.5 / img->scale - img->offset_x + c * 3 / (W * img->scale);
	else
		k = 1 / img->scale + img->offset_y - c * 2 / (H * img->scale);
	return (k);
}

int	julia_limit(t_complex c, t_complex z)
{
	int		n;
	float	re;
	float	im;

	n = 0;
	while (n < 200)
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

int	julia_palette(int n)
{
	int	color;

	if (n < 20)
		color = 5.26 * n + 60;
	else if (n >= 20 && n < 65)
		color = -256 * n * 10 + 13167612;
	else if (n >= 65)
		color = -256 * n + 16777215;
	return (color);
}
