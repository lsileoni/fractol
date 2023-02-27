/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:23 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/27 11:26:58 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		colorschemes(p->color_scheme % COLOR_SCHEMES, pixel, iters, buf);
}

static void	put_text(t_app *app)
{
	char	*printable_string;
	char	*placeholder;

	placeholder = ft_ulltoa_base(app->params->movement_factor, 10);
	printable_string = ft_strjoin("zoom level: ", placeholder);
	mlx_string_put(app->mlx, app->win, 0, 0, 0xFFFFFF, printable_string);
	free(printable_string);
	free(placeholder);
	placeholder = ft_ulltoa_base(app->params->iter_max, 10);
	printable_string = ft_strjoin("iteration count: ", placeholder);
	mlx_string_put(app->mlx, app->win, 0, 20, 0xFFFFFF, printable_string);
	free(printable_string);
	free(placeholder);
}

static void	paint_pixel(t_app *app, t_window *win, \
		t_framebuffer *fb, int set_type)
{
	if (set_type == MANDELBROT)
		color_buffer(fb->buffer, (unsigned char)mandelbrot_check(win->x, \
					win->y, app->params), fb->pixel, app->params);
	else
		color_buffer(fb->buffer, (unsigned char)julia_check(win->x, \
					win->y, app), fb->pixel, app->params);
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
	put_text(app);
}
