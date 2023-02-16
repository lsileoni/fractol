#include "fractol.h"
#include "./libft/src/libft.h"
#include "minilibx_opengl/mlx.h"


// int	render_frame(t_app *app)
// {
// 	return (0);
// }

void	define_hooks(t_app *app)
{
	mlx_hook(app->win, 2, 1L<<0, key_down, app);
	mlx_hook(app->win, 3, 1L<<0, key_up, app);
	mlx_hook(app->win, 6, 1L<<6, mouse_pos, app);
	mlx_hook(app->win, 4, 1L<<0, mouse_hook, app);
	mlx_hook(app->win, 17, 1L<<0, close_window, app);
	// mlx_loop_hook(app->mlx, render_frame, app);
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
