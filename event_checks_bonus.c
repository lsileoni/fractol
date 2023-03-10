/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_checks_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:25:54 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/27 11:35:49 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	reset_view(t_app *app, t_window *w)
{
	w->max_width = STARTING_VIEW;
	w->min_width = -STARTING_VIEW;
	w->max_height = STARTING_VIEW;
	w->min_height = -STARTING_VIEW;
	app->params->movement_factor = 1.0;
	app->params->iter_max = STARTING_ITERATIONS;
	w->pixel_width = (w->max_width - w->min_width) / w->window_width;
	w->pixel_height = (w->max_height - w->min_height) / w->window_height;
}

void	check_modifier_actions(t_app *app, t_window *win,
		unsigned char *key_down_flags)
{
	if (key_down_flags[I_KEY])
	{
		app->params->iter_max += 1;
		paint_set(app);
	}
	if (key_down_flags[Z_KEY])
		zoom_in_static(app, app->params);
	if (key_down_flags[R_KEY])
	{
		reset_view(app, win);
		paint_set(app);
	}
}

void	check_movement_actions(t_app *app, t_window *win,
		unsigned char *key_down_flags)
{
	if (key_down_flags[LEFT_ARROW])
	{
		win->min_width -= 0.1 / app->params->movement_factor;
		win->max_width -= 0.1 / app->params->movement_factor;
		paint_set(app);
	}
	if (key_down_flags[RIGHT_ARROW])
	{
		win->min_width += 0.1 / app->params->movement_factor;
		win->max_width += 0.1 / app->params->movement_factor;
		paint_set(app);
	}
	if (key_down_flags[UP_ARROW])
	{
		win->max_height -= 0.1 / app->params->movement_factor;
		win->min_height -= 0.1 / app->params->movement_factor;
		paint_set(app);
	}
	if (key_down_flags[DOWN_ARROW])
	{
		win->max_height += 0.1 / app->params->movement_factor;
		win->min_height += 0.1 / app->params->movement_factor;
		paint_set(app);
	}
}

void	check_mouse_actions(t_app *app)
{
	t_flags	*flags;

	flags = app->flags;
	if (app->flags->scroll_up)
		zoom_in_complex(app, app->params->mouse_x, app->params->mouse_y);
	if (app->flags->scroll_down)
		zoom_out_static(app);
	if (app->flags->mouse_moved)
	{
		if (app->flags->mouse_one_down)
			paint_set(app);
	}
}
