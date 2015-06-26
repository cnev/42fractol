#include "../include/fractol.h"

/*définir x1 = -2.1
définir x2 = 0.6
définir y1 = -1.2
définir y2 = 1.2
définir zoom = 100 // pour une distance de 1 sur le plan, on a 100 pixel sur l'image
définir iteration_max = 50

définir image_x = (x2 - x1) * zoom
définir image_y = (y2 - y1) * zoom

Pour x = 0 tant que x < image_x par pas de 1
	Pour y = 0 tant que y < image_y par pas de 1
		définir c_r = x / zoom + x1
		définir c_i = y / zoom + y1
		définir z_r = 0
		définir z_i = 0
		définir i = 0

		Faire
			définir tmp = z_r
			z_r = z_r*z_r - z_i*z_i + c_r
			z_i = 2*z_i*tmp + c_i
			i = i+1
		Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

		si i = iteration_max
			dessiner en noir le pixel de coordonné (x; x)
		sinon
			dessiner avec couleur rgb(0, 0, i*255/iterations_max) le pixel de coordonné (x; x)
		finSi
	finPour
finPour*/

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
