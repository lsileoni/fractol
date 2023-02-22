/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:11 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/22 22:30:46 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	return (0);
}

int	key_down(int key, t_app *app)
{
	if (key == C_KEY)
	{
		app->params->color_scheme++;
		paint_pattern(app);
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
