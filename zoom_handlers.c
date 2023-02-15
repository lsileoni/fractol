#include "fractol.h"

void	zoom_out_static(t_app *app)
{
	double		width_diff;
	double		height_diff;
	double		x_midpoint;
	double		y_midpoint;
	t_params	*p;

	p = app->params;
	x_midpoint = (p->max_width + p->min_width) / 2;
	y_midpoint = (p->max_height + p->min_height) / 2;
	width_diff = p->max_width - p->min_width;
	height_diff = p->max_height - p->min_height;
	p->max_width = x_midpoint + width_diff;
	p->min_width = x_midpoint - width_diff;
	p->max_height = y_midpoint + height_diff;
	p->min_height = y_midpoint - height_diff;
	p->movement_factor /= 2;
	paint_pattern(app);
}

void	zoom_in_static(t_params *p)
{
	double	midpoint;

	midpoint = 0;
	midpoint = (p->max_width + p->min_width) / 2.0;
	p->max_width = (p->max_width + midpoint) / 2.0;
	p->min_width = (p->min_width + midpoint) / 2.0;
	midpoint = (p->min_height + p->max_height) / 2.0;
	p->max_height = (p->max_height + midpoint) / 2.0;
	p->min_height = (p->min_height + midpoint) / 2.0;
	p->movement_factor *= 2;
}

void	zoom_in_complex(t_complex z, t_app *app)
{
	t_params	*p;

	p = app->params;
	p->max_width = (p->max_width + z.r) / 2;
	p->min_width = (p->min_width + z.r) / 2;
	p->max_height = (p->max_height + z.i) / 2;
	p->min_height = (p->min_height + z.i) / 2;
	p->movement_factor *= 2;
	paint_pattern(app);
}

