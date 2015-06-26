#include "../include/fractol.h"

void			init_buddhabrot(t_info *info, t_data *data)
{
	info->x1 = -2.1;
	info->x2 = 0.6;
	info->y1 = -1.2;
	info->y2 = 1.2;
	info->zoom = 100;
	info->max_iter = 100;
	info->image_x = (info->x2 - info->x1) * zoom;
	info->image_y = (info->y2 - info->y1) * zoom;
}

int				calc_buddhabrot(t_info *info, t_data *data, t_list **list)
{
	float			tmp;

	tmp = data->z_r;
	data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
	data->z_i =2 * data->z_i * tmp + data->c_i;
	data->i++;
	list_pushback(list, create_buddha_data((data->z_r - info->x1) * info->zoom,
		(data->z_i - info->y1) * info->zoom);
	while (data->z_r * data->z_r + data->z_i*data->z_i < 4
		&& data->i < info->max_iter)
	{
		tmp = data->z_r;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i =2 * data->z_i * tmp + data->c_i;
		data->i++;
		list_pushback(list, create_buddha_data((data->z_r - info->x1) * info->zoom,
		(data->z_i - info->y1) * info->zoom);
	}
	return (data->i)
}

int				exec_buddhabrot(t_env *e)
{
	t_list			*pixel_list;
	int				pixels[]

	pixel_list = NULL;
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
			calc_buddhabrot(&(e->info), &(e->data), &pixel_list);
		}
		build_pixel_array(pixels, &(e->info), &(e->data), pixel_list);
	}
}
