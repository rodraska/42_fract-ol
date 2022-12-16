#include "../fract_ol.h"


int	handle_keypress(int keysym, t_mlx_data *data)
{   
	if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx, data->mlx_win);
        data->mlx_win = NULL;
    }
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
	*(unsigned int*)pixel = color;
}

int render_rect(t_data *img, t_rect rect)
{
    int i;
    int j;

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
        {
            my_mlx_pixel_put(img, j++, i, rect.color);
        }
        i++;
    }
    return (0);
}

void    render_background(t_data *img, int color)
{
    int i;
    int j;

    i = 0;
    while (i < H / 2)
    {
        j = 0;
        while (j < W / 2)
            my_mlx_pixel_put(img, j++, i, color);
        ++i;
    }
}

int	render(t_mlx_data *data)
{
    if (data->mlx_win == NULL)
		return (1);
    render_background(&data->img, WHITE);
	render_rect(&data->img, (t_rect){W / 2 - 100, H / 2 - 100, 100, 100, GREEN});
    render_rect(&data->img, (t_rect){0, 0, 100, 100, RED});
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_mlx_data data;

	data.mlx = mlx_init();
    if (!data.mlx)
        return (MLX_ERROR);
    data.mlx_win = mlx_new_window(data.mlx, W / 2, H / 2, "Hello world!");
    if (!data.mlx_win)
    {
        free(data.mlx_win);
        return (MLX_ERROR);
    }
    data.img.img = mlx_new_image(data.mlx, W / 2, H / 2);
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
    mlx_loop_hook(data.mlx, &render, &data);
    mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &data);
    mlx_loop(data.mlx);
    mlx_destroy_image(data.mlx, data.img.img);
    mlx_destroy_display(data.mlx);
    free(data.mlx);
    return (0);
}