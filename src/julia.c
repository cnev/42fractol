#include "../include/fractol.h"

void			init_julia(t_info *info, t_data *data)
{
	info->x1 = -1;
	info->x2 = 1;
	info->y1 = -1.2;
	info->y2 = 1.2;
	info->zoom = 100;
	info->max_iter = 150;
	info->image_x = (info->x2 - info->x1) * zoom;
	info->image_y = (info->y2 - info->y1) * zoom;
}

static int			exec_julia(t_env *e)
{
	e->data.x = -1;
	e->data.y = -1;
	while (++e->data.x < e->info.image_x)
	{
		while (++e->data.y < e->info.image_y)
		{
			e->data.c_r = 0.285;
			e->data.c_i = 0.01;
			e->data.z_r = e->data.x / e->info.zoom + e->info.x1;
			e->data.z_i = e->data.y / e->info.zoom + e->info.y1;
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
