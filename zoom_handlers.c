/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:39 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/27 11:37:16 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_out_static(t_app *app)
{
	double		width_diff;
	double		height_diff;
	t_params	*p;
	t_window	*win;

	p = app->params;
	win = p->window_params;
	win->x_midpoint = (win->max_width + win->min_width) / 2.0;
	win->y_midpoint = (win->max_height + win->min_height) / 2.0;
	width_diff = win->max_width - win->min_width;
	height_diff = win->max_height - win->min_height;
	win->max_width = win->x_midpoint + width_diff;
	win->min_width = win->x_midpoint - width_diff;
	win->max_height = win->y_midpoint + height_diff;
	win->min_height = win->y_midpoint - height_diff;
	p->movement_factor /= 2.0;
	win->pixel_width = (win->max_width - win->min_width) / win->window_width;
	win->pixel_height = (win->max_height - win->min_height)
		/ win->window_height;
	paint_set(app);
}

void	zoom_in_complex(t_app *app, int x, int y)
{
	t_params	*p;
	t_window	*win;
	t_complex	z;

	p = app->params;
	win = p->window_params;
	z.r = win->min_width + (x * win->pixel_width);
	z.i = win->min_height + (y * win->pixel_height);
	win->max_width = (win->max_width + z.r) / 2.0;
	win->min_width = (win->min_width + z.r) / 2.0;
	win->max_height = (win->max_height + z.i) / 2.0;
	win->min_height = (win->min_height + z.i) / 2.0;
	win->pixel_width = (win->max_width - win->min_width) / win->window_width;
	win->pixel_height = (win->max_height - win->min_height) \
						/ win->window_height;
	p->movement_factor *= 2.0;
	paint_set(app);
}
