/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:11 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/27 11:36:26 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mouse_hook(int button, int x, int y, t_app *app)
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
	{
		if (!app->flags->mouse_one_down)
			app->flags->mouse_one_down = 1;
		else
		{
			app->flags->mouse_one_down = 0;
			app->params->set->c.i = window->min_height + (app->params->mouse_y
					* window->pixel_height);
			app->params->set->c.r = window->min_width + (app->params->mouse_x
					* window->pixel_width);
			paint_set(app);
		}
	}
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
	if (key == C_KEY)
	{
		app->params->color_scheme++;
		paint_set(app);
	}
	if (key == H_KEY)
	{
		app->draw_text *= -1;
		paint_set(app);
	}
	if (key == S_KEY)
	{
		if (app->params->set->set_type == JULIA)
			app->params->set->set_type = BURNINGSHIP;
		else if (app->params->set->set_type == MANDELBROT)
			app->params->set->set_type = JULIA;
		else
			app->params->set->set_type = MANDELBROT;
		paint_set(app);
	}
	switchboard(key, app);
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
	free(app->flags->key_down_flags);
	free(app->flags);
	exit(0);
	return (0);
}
