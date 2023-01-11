/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:47:55 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/11 16:07:39 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_error(void)
{
	int	a;

	a = write(1, "Error in input\n", 16);
	a = write(1, "The first parameter should be M ", 33);
	a = write(1, "for Mandelbrot or J for Julia\n", 31);
	a = write(1, "The second parameter is the seed for the Julia ", 48);
	a = write(1, "set, or the number of iterations for Mandelbrot", 49);
	a = write(1, "(*10) and should be a number between 0 and 100\n", 48);
	(void)a;
	exit (0);
}

int	ft_input(int ac, char **av)
{
	if (ac != 3)
		return (0);
	else if (av[1][0] != 'M' && av[1][0] != 'J')
		return (0);
	else if (!is_number(av[2]))
		return (0);
	else if (ft_seed(av[2]) > 0.5 || ft_seed(av[2]) < 0)
		return (0);
	return (1);
}

int	render(t_mlx_data *data)
{
	if (data->mlx_win == NULL)
		return (1);
	if (data->fractal == 'M')
		render_mandelbrot(&data->img);
	else if (data->fractal == 'J')
		render_julia(&data->img);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	static t_mlx_data	data;

	if (!ft_input(ac, av))
		ft_error();
	data.mlx = mlx_init();
	if (!data.mlx)
		return (MLX_ERROR);
	data.mlx_win = mlx_new_window(data.mlx, W, H, "Hello world!");
	if (!data.mlx_win)
	{
		free(data.mlx_win);
		return (MLX_ERROR);
	}
	data.fractal = av[1][0];
	data.img.seed = ft_seed(av[2]);
	data.img.scale = 1;
	data.img.img = mlx_new_image(data.mlx, W, H);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, \
	&data.img.line_length, &data.img.endian);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_key_hook(data.mlx_win, &handle_keypress, &data);
	mlx_mouse_hook(data.mlx_win, &handle_mouse, &data);
	mlx_hook(data.mlx_win, 17, 0, ft_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
