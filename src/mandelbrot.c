#include "../include/fractol.h"

static void		init_mandelbrot(t_info *info, t_data *data)
{
	info->x1 = -2.1;
	info->x2 = 0.6;
	info->y1 = -1.2;
	info->y2 = 1.2;
	info->zoom = 100;
	info->max_iter = 50;
	info->image_x = (info->x2 - info->x1) * zoom;
	info->image_y = (info->y2 - info->y1) * zoom;
}

int		test_fractal(t_info *info, t_data *data)
{
	float			tmp;

	tmp = data->z_r;
	data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
	data->z_i =2 * data->z_i * tmp + data->c_i;
	data->i++;
	while (data->z_r * data->z_r + data->z_i*data->z_i < 4
		&& data->i < info->max_iter)
	{
		tmp = data->z_r;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i =2 * data->z_i * tmp + data->c_i;
		data->i++;
	}
	return (data->i)
}

int				exec_mandelbrot(t_env *e)
{
	e->data.x = -1;
	e->data.y = -1;
	while (++e->data.x < e->info.image_x)
	{
		while (++e->data.y < e->info.image_y)
		{
			e->data.c_r = e->info.x / e->info.zoom + e->info.x1;
			e->data.c_i = e->info.y / e->info.zoom + e->info.y1;
			e->data.z_r = 0;
			e->data.z_i = 0;
			e->data.i = 0;
			if (test_fractal(&(e->info), &(e->data)) == info.max_iter)
			{
				// Affecter noir au pixel
			}
			else
			{
				// Affecter une couleur au pixel
			}
		}
	}
}
