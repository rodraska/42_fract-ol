#include "../fract_ol.h"

int	render(t_mlx_data *data)
{
    if (data->mlx_win == NULL)
		return (1);
    render_background(&data->img, WHITE);
	//render_rect(&data->img, (t_rect){(100 + (data->img.offset_x * data->img.scale)) ,(100 + (data->img.offset_y * data->img.scale)) / (sqrt(data->img.scale) / 2), 100 * sqrt(data->img.scale), 100 * sqrt(data->img.scale), GREEN});
    render_quad(&data->img, (t_rect){150 + data->img.offset_x, 150 + data->img.offset_y, 100 * data->img.scale, 100 * data->img.scale, RED});
    render_circle(&data->img, (t_circle){W / 2 + data->img.offset_x, H / 2 + data->img.offset_y, 100 * data->img.scale, BLUE});
    //render_portugal(&data->img);
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
    data.img.offset_x = 0;
    data.img.offset_y = 0;
    data.img.scale = 1;
    data.img.img = mlx_new_image(data.mlx, W, H);
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
    mlx_loop_hook(data.mlx, &render, &data);
    mlx_key_hook(data.mlx_win, &handle_keypress, &data);
    mlx_mouse_hook(data.mlx_win, &handle_mouse, &data);
    mlx_loop(data.mlx);
    mlx_destroy_image(data.mlx, data.img.img);
    mlx_destroy_display(data.mlx);
    free(data.mlx);
    return (0);
}