#include "../fract_ol.h"

int	handle_keypress(int keysym, t_mlx_data *data)
{   
    
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->mlx_win);

	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->mlx_win);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int render_rect(t_mlx_data *data, t_rect rect)
{
    int i;
    int j;

    if (data->mlx_win == NULL)
        return (MLX_ERROR);
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            mlx_pixel_put(data->mlx, data->mlx_win, j++, i, rect.color);
        i++;
    }
    return (0);
}

int	render(t_mlx_data *data)
{
    if (data->mlx_win == NULL)
		return (1);
	render_rect(data, (t_rect){W - 100, H - 100, 100, 100, GREEN});
    render_rect(data, (t_rect){0, 0, 100, 100, RED});
	return (0);
}

int	main(void)
{
	t_mlx_data data;

	data.mlx = mlx_init();
    if (!data.mlx)
        return (MLX_ERROR);
    data.mlx_win = mlx_new_window(data.mlx, W, H, "Hello world!");
    if (!data.mlx_win)
    {
        free(data.mlx_win);
        return (MLX_ERROR);
    }

    
    mlx_loop_hook(data.mlx, &render, &data);
    mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &data);

    mlx_loop(data.mlx);

    mlx_destroy_display(data.mlx);
    free(data.mlx);

    /* img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    ft_portugal(&img);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx); */

    return (0);
}