#include "../fract_ol.h"

int	handle_keypress(int keysym, t_mlx_data *data)
{   
	if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx, data->mlx_win);
        data->mlx_win = NULL;
    }
	if (keysym == XK_Right || keysym == XK_d)
		data->img.offset_x += 10;
	if (keysym == XK_Left || keysym == XK_a)
		data->img.offset_x -= 10;
	if (keysym == XK_Up || keysym == XK_w)
		data->img.offset_y -= 10;
	if (keysym == XK_Down || keysym == XK_s)
		data->img.offset_y += 10;
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