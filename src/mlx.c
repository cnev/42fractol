#include "../include/fractol.h"

static int		init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCN_W, SCN_H, "Fractals");
	return (0);
}

int				expose_hook(t_env *e)
{
	if (e->type == TYPE_JULIA)
		exec_julia(e);
	else if (e->type == TYPE_MANDELBROT)
		exec_mandelbrot(e);
	else if (e->type == TYPE_BUDDHABROT)
		exec_buddhabrot(e);
	return (0);
}
