/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_checks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:28 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/22 22:34:11 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ship_check(int x, int y, t_params *p)
{
	t_window		*win;
	t_set			*set;
	unsigned int	iter_max;

	iter_max = p->iter_max;
	set = p->set;
	win = p->window_params;
	set->z.r = 0.0;
	set->z.i = 0.0;
	set->c.r = win->min_width + (x * win->pixel_width);
	set->c.i = win->min_height + (y * win->pixel_height);
	while (fabs(set->z.r) + fabs(set->z.i) < BOUNDING_BOX && iter_max)
	{
		set->z = com_abs(set->z);
		set->z = com_mul(set->z, set->z);
		set->z = com_add(set->z, set->c);
		iter_max--;
	}
	return ((unsigned char)(iter_max));
}

static void	z_squared_plus_c(t_complex *z, t_complex *c, t_complex *z_s)
{
	z->i = 2.0 * z->r * z->i + c->i;
	z->r = z_s->r - z_s->i + c->r;
	z_s->r = z->r * z->r;
	z_s->i = z->i * z->i;
}

int	julia_check(int x, int y, t_app *app)
{
	t_params		*p;
	t_window		*win;
	t_set			*set;
	unsigned int	iter_max;

	p = app->params;
	set = p->set;
	win = p->window_params;
	set->z.i = (win->min_height + (y * win->pixel_height)) * -1.0;
	set->z.r = win->min_width + (x * win->pixel_width);
	set->z_s.r = set->z.r * set->z.r;
	set->z_s.i = set->z.i * set->z.i;
	iter_max = p->iter_max;
	if (app->flags->mouse_one_down)
	{
		set->c.i = win->min_height + (p->mouse_y * win->pixel_height);
		set->c.r = win->min_width + (p->mouse_x * win->pixel_width);
	}
	while (fabs(set->z_s.r) + fabs(set->z_s.i) < BOUNDING_BOX && --iter_max)
		z_squared_plus_c(&set->z, &set->c, &set->z_s);
	return ((unsigned char)(iter_max));
}

static int	cardioid_check(t_set *set)
{
	if (set->c.r * (1 + set->c.r * (8 * set->c.r * set->c.r + \
					(16 * set->c.i * set->c.i - 3))) + \
					set->c.i * set->c.i * \
					(9 * set->c.i * set->c.i - 3) < 3.0 / 32 \
					|| \
					((set->c.r + 1) * (set->c.r + 1) + set->c.i * \
					set->c.i) < 1.0 / 16)
		return (1);
	return (0);
}

int	mandelbrot_check(int x, int y, t_params *p)
{
	t_window		*win;
	t_set			*set;
	unsigned int	iter_max;

	set = p->set;
	win = p->window_params;
	set->z.r = 0.0;
	set->z.i = 0.0;
	set->z_s.r = 0.0;
	set->z_s.i = 0.0;
	iter_max = p->iter_max;
	set->c.r = win->min_width + (x * win->pixel_width);
	set->c.i = win->min_height + (y * win->pixel_height);
	if (cardioid_check(set))
		return ((unsigned char)0);
	while (fabs(set->z_s.r) + fabs(set->z_s.i) < BOUNDING_BOX && --iter_max)
		z_squared_plus_c(&set->z, &set->c, &set->z_s);
	return ((unsigned char)(iter_max));
}
