#include "fractol.h"
#include "./libft/src/libft.h"
#include "minilibx_opengl/mlx.h"

t_complex divide(t_complex x,t_complex y){
    t_complex z;
    z.r = (x.r*y.r + x.i*y.i)/(y.r*y.r+y.i*y.i);
    z.i = (x.i*y.r - x.r*y.i)/(y.r*y.r + y.i*y.i);
    return z;
}

void	define_hooks(t_app *app)
{
	mlx_hook(app->win, 2, 1L<<0, key_down, app);
	mlx_hook(app->win, 3, 1L<<0, key_up, app);
	mlx_hook(app->win, 6, 1L<<6, mouse_pos, app);
	mlx_hook(app->win, 4, 1L<<0, mouse_hook, app);
	mlx_hook(app->win, 17, 1L<<0, close_window, app);
}

int	main(int argc, char **argv)
{
	t_app			*app;
	t_params		*params;
	t_set			*set;
	t_framebuffer	*fb;

	if (!(params = init_params(ft_atoi(argv[2]), ft_atoi(argv[3]))) || argc < 2)
		exit(1);
	if (!(app = init_app(params)))
	{
		free(params);
		exit(1);
	}
	app->params = params;
	if (!(set = init_set(argv[1])) || !(fb = init_framebuffer(app)))
	{
		free(params);
		free(app);
		exit(1);
	}
	params->set = set;
	app->fb = fb;
	define_hooks(app);
	paint_pattern(app);
	mlx_loop(app->mlx);
}
