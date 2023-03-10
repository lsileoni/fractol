/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:23 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/27 11:36:59 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	put_controls(t_app *app)
{
	mlx_string_put(app->mlx, app->win, 5, 60, 0x00000000, "Controls");
	mlx_string_put(app->mlx, app->win, 5, 80, 0x00000000, "---------------");
	mlx_string_put(app->mlx, app->win, 5, 100, 0x00000000, \
										"Arrow keys: Movement");
	mlx_string_put(app->mlx, app->win, 5, 120, 0x00000000, "Z: Zoom");
	mlx_string_put(app->mlx, app->win, 5, 140, 0x00000000, "C: Cycle color");
	mlx_string_put(app->mlx, app->win, 5, 160, 0x00000000, \
										"I: Increase iterations");
	mlx_string_put(app->mlx, app->win, 5, 180, 0x00000000, \
										"Mouse scroll wheel: Zoom in and out");
	mlx_string_put(app->mlx, app->win, 5, 200, 0x00000000, "H: Toggle help");
	mlx_string_put(app->mlx, app->win, 5, 220, 0x00000000, "R: Reset position");
	mlx_string_put(app->mlx, app->win, 5, 240, 0x00000000, "S: Switch set");
	mlx_string_put(app->mlx, app->win, 5, 260, 0x00000000, \
										"ESC: Quit application");
}

static void	color_buffer(char *buf, unsigned char iters, int pixel, t_params *p)
{
	if (!iters)
	{
		buf[pixel] = (unsigned char)0;
		buf[pixel + 1] = (unsigned char)0;
		buf[pixel + 2] = (unsigned char)0;
		buf[pixel + 3] = (unsigned char)0;
	}
	else
		colorboard(p->color_scheme, pixel, iters, buf);
}

static void	put_text(t_app *app)
{
	char	*printable_string;
	char	*placeholder;

	placeholder = ft_ulltoa_base(app->params->movement_factor, 10);
	printable_string = ft_strjoin("zoom level: ", placeholder);
	mlx_string_put(app->mlx, app->win, 0, 0, 0x00000000, printable_string);
	free(printable_string);
	free(placeholder);
	placeholder = ft_ulltoa_base(app->params->iter_max, 10);
	printable_string = ft_strjoin("iteration count: ", placeholder);
	mlx_string_put(app->mlx, app->win, 0, 20, 0x00000000, printable_string);
	free(printable_string);
	free(placeholder);
	put_controls(app);
}

static void	paint_pixel(t_app *app, t_window *win, \
		t_framebuffer *fb, int set_type)
{
	if (set_type == MANDELBROT)
		color_buffer(fb->buffer, (unsigned char)mandelbrot_check(win->x, \
					win->y, app->params), fb->pixel, app->params);
	else if (set_type == JULIA)
		color_buffer(fb->buffer, (unsigned char)julia_check(win->x, \
					win->y, app), fb->pixel, app->params);
	else
		color_buffer(fb->buffer, (unsigned char)ship_check(win->x, \
					win->y, app->params), fb->pixel, app->params);
}

void	paint_set(t_app *app)
{
	t_framebuffer	*fb;
	t_window		*win;

	fb = app->fb;
	win = app->params->window_params;
	win->y = -1;
	while (++win->y < win->window_height)
	{
		win->x = -1;
		while (++win->x < win->window_width)
		{
			paint_pixel(app, win, fb, app->params->set->set_type);
			fb->pixel += 4;
		}
	}
	fb->pixel = 0;
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
	if (app->draw_text == 1)
		put_text(app);
}
