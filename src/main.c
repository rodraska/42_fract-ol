#include "../fract_ol.h"

int	render(t_mlx_data *data)
{
    if (data->mlx_win == NULL)
		return (1);
    render_background(&data->img, WHITE);
	/* render_rect(&data->img, (t_rect){W - 100, H - 100, 100, 100, GREEN});
    render_rect(&data->img, (t_rect){0, 0, 100, 100, RED});
    render_circle(&data->img, (t_circle){W / 2, H / 2, 200, BLUE}); */
    render_portugal(&data->img);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
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
    data.img.img = mlx_new_image(data.mlx, W, H);
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
    mlx_loop_hook(data.mlx, &render, &data);
    mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &data);
    mlx_loop(data.mlx);
    mlx_destroy_image(data.mlx, data.img.img);
    mlx_destroy_display(data.mlx);
    free(data.mlx);
    return (0);
}