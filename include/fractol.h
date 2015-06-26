#ifndef FRACTOL_H
# define FRACTOL_H
# define TYPE_JULIA			1
# define TYPE_MANDELBROT	2
# define TYPE_BUDDHABROT	3

typedef struct		s_info
{
	float			x1;
	float			x1;
	float			x1;
	float			x1;
	int				zoom;
	int				max_iter;
	int				image_x;
	int				image_y;
}					t_info;

typedef struct		s_data
{
	int				x;
	int				y;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	int				i;
}					t_data;

typedef struct		s_env
{
	t_info			info;
	t_data			data;
}					t_env;

#endif
