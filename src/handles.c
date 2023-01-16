/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:47:46 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/16 10:01:30 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	handle_keypress(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		ft_close(data);
	if (keysym == XK_Right)
		data->img.offset_x += 0.05 / data->img.scale;
	if (keysym == XK_Left)
		data->img.offset_x -= 0.05 / data->img.scale;
	if (keysym == XK_Up)
		data->img.offset_y -= 0.05 / data->img.scale;
	if (keysym == XK_Down)
		data->img.offset_y += 0.05 / data->img.scale;
	if (keysym == XK_a)
		data->img.julia_x -= 0.005;
	if (keysym == XK_d)
		data->img.julia_x += 0.005;
	if (keysym == XK_s)
		data->img.julia_y -= 0.005;
	if (keysym == XK_w)
		data->img.julia_y += 0.005;
	return (0);
}

int	handle_mouse(int button, int x, int y, t_mlx_data *data)
{
	if (button == 4)
	{
		data->img.offset_x += (W / 2 - x) * 3 / (W * data->img.scale);
		data->img.offset_y += (H / 2 - y) * 2 / (H * data->img.scale);
		data->img.scale *= 1.2;
	}
	if (button == 5)
	{
		data->img.scale /= 1.2;
	}
	return (0);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->mlx_win);
	return (0);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

int	ft_close(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}
