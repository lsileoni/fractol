/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:28 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/19 22:26:29 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	thorn_check(int x, int y, t_params *p)
{
	t_set		*set;
	t_window	*win;
	t_complex	Z_orig;
	t_complex	Z;
	t_complex	C;
	t_complex	Z_old;
	int			iter_max;
	int			period;

	iter_max = p->iter_max;
	set = p->set;
	win = p->window_params;
	Z.r = 0.7;
	Z.i = 0.725;
	C.r = win->min_width + (x * win->pixel_width);
	C.i = win->min_height + (y * win->pixel_height);
	Z_old.r = 0.0;
	Z_old.i = 0.0;
	period = 0;
	while (fabs(Z.r) < BOUNDING_BOX && fabs(Z.i) < BOUNDING_BOX && iter_max)
	{
		Z_orig = Z;
		Z = com_mul(Z, Z);
		Z.r += C.r;
		Z.i += C.i;
		if (Z.r == Z_old.r && Z.i == Z_old.i)
		{
			iter_max = 0;
			break ;
		}
		period++;
		if (period > 20)
		{
			period = 0;
			Z_old = Z;
		}
		iter_max--;
	}
	return ((unsigned char)(iter_max));
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
	iter_max = p->iter_max;
	set->z.i = win->min_height + (y * win->pixel_height);
	set->z.r = win->min_width + (x * win->pixel_width);
	if (app->flags->mouse_one_down)
	{
		set->c.i = win->min_height + (p->mouse_y * win->pixel_height);
		set->c.r = win->min_width + (p->mouse_x * win->pixel_width);
	}
	set->z_s.r = set->z.r * set->z.r;
	set->z_s.i = set->z.i * set->z.i;
	while (fabs(set->z_s.r) < BOUNDING_BOX && fabs(set->z_s.i) < BOUNDING_BOX
		&& iter_max)
	{
		set->z.i = 2.0 * set->z.r * set->z.i + set->c.i;
		set->z.r = set->z_s.r - set->z_s.i + set->c.r;
		set->z_s.r = set->z.r * set->z.r;
		set->z_s.i = set->z.i * set->z.i;
		iter_max--;
	}
	return ((unsigned char)(iter_max));
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
	while (fabs(set->z.r) < BOUNDING_BOX && fabs(set->z.i) < BOUNDING_BOX
		&& iter_max)
	{
		set->z.i = 2.0 * set->z.r * set->z.i + set->c.i;
		set->z.r = set->z_s.r - set->z_s.i + set->c.r;
		set->z_s.r = set->z.r * set->z.r;
		set->z_s.i = set->z.i * set->z.i;
		iter_max--;
	}
	return ((unsigned char)(iter_max));
}
