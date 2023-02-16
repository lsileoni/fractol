#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_app *app)
{
	t_complex	z;
	t_window	*window;
	
	window = app->params->window_params;
	z.r = window->min_width + (x * window->pixel_width);
	z.i = window->min_height + (y * window->pixel_height);
	if (button == 5)
		zoom_in_complex(app, z);
	else if (button == 4)
		zoom_out_static(app);
	return (0);
}

int mouse_pos(int x, int y, t_app *app)
{
	app->params->mouse_x = x;
	app->params->mouse_y = y;
	if (app->params->set->set_type == JULIA)
		paint_pattern(app);
	return (0);
}

int	key_up(int key, t_app *app)
{
	if (key == ESC)
	{
		mlx_destroy_image(app->mlx, app->img);
		mlx_destroy_window(app->mlx, app->win);
		free(app->params->set);
		free(app->params->window_params);
		free(app->params);
		free(app->fb);
		free(app);
		exit(0);
	}
	return (0);
}

int	key_down(int key, t_app *app)
{
	switchboard(key, app);
	return (0);
}

int	close_window(t_app *app)
{
	mlx_destroy_image(app->mlx, app->img);
	mlx_destroy_window(app->mlx, app->win);
	free(app->params->set);
	free(app->params->window_params);
	free(app->params);
	free(app->fb);
	free(app);
	exit(0);
}
