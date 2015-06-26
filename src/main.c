#include "../include/fractol.h"

static void			launch_fractol(int type)
{
	t_env			e;

	e.type = type;
	init_mlx(&(e.mlx));
	if (type == TYPE_JULIA)
		init_julia(&(e.info), &(e.data));
	else if (type == TYPE_MANDELBROT)
		init_mandelbrot(&(e.info), &(e.data));
	else if (type == TYPE_BUDDHABROT)
		init_buddhabrot(&(e.info), &(e.data));
	mlx_expose_hook(e.mlx.win, expose_hook, &e);
	mlx_loop(e.mlx.mlx);
}

int					main(int ac, char **av)
{
	if (ac < 2)
		ft_putendl("No specified type. [julia | mandelbrot | buddhabrot");
	else if (!ft_strcmp(av[2], "julia"))
		launch_fractol(TYPE_JULIA);
	else if (!ft_strcmp(av[2], "mandelbrot"))
		launch_fractol(TYPE_MANDELBROT);
	else if (!ft_strcmp(av[2], "buddhabrot"))
		launch_fractol(TYPE_BUDDHABROT);
	else
		ft_putendl("Error detecting type. [julia | mandelbrot | buddhabrot");
	return (0);
}
`
