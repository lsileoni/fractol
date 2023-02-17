#include "fractol.h"
#include "./libft/src/libft.h"

int		mouse_hook(int button, int x, int y, t_app *app)
{
	t_window	*window;
	
	window = app->params->window_params;
	app->params->mouse_x = x;
	app->params->mouse_y = y;
	if (button == SCROLL_DOWN)
		app->flags->scroll_up = 1;
	else if (button == SCROLL_UP)
		app->flags->scroll_down = 1;
	else if (button == MOUSE_ONE_DOWN)
		app->flags->mouse_one_down = 1;
	return (0);
}

int	mouse_movement_hook(int x, int y, t_app *app)
{
	app->params->mouse_x = x;
	app->params->mouse_y = y;
	if (app->params->set->set_type == JULIA)
		app->flags->mouse_moved = 1;
	return (0);
}

int	key_down(int key, t_app *app)
{
	switchboard(key, app, 1);
	return (0);
}

int	key_up(int key, t_app *app)
{
	key = 0;
	ft_bzero(app->flags->key_down_flags, KEY_RANGE);
	return (0);
}

int	close_window(t_app *app)
{
	mlx_destroy_image(app->mlx, app->img);
	mlx_destroy_window(app->mlx, app->win);
	free(app->params->window_params);
	free(app->params->set);
	free(app->params);
	free(app->flags->key_down_flags);
	free(app->fb);
	free(app->flags);
	free(app);
	exit(0);
	return (0);
}
