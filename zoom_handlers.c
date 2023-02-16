#include "fractol.h"

void	zoom_out_static(t_app *app)
{
	double		width_diff;
	double		height_diff;
	t_params	*p;
	t_window	*win;

	p = app->params;
	win = p->window_params;
	win->x_midpoint = (win->max_width + win->min_width) / 2;
	win->y_midpoint = (win->max_height + win->min_height) / 2;
	width_diff = win->max_width - win->min_width;
	height_diff = win->max_height - win->min_height;
	win->max_width = win->x_midpoint + width_diff;
	win->min_width = win->x_midpoint - width_diff;
	win->max_height = win->y_midpoint + height_diff;
	win->min_height = win->y_midpoint - height_diff;
	p->movement_factor /= 2;
	win->pixel_width = (win->max_width - win->min_width) / win->window_width;
	win->pixel_height = (win->max_height - win->min_height) / win->window_height;
	paint_pattern(app);
}

void	zoom_in_static(t_params *p)
{
	t_window	*win;
	
	win = p->window_params;
	win->x_midpoint = (win->max_width + win->min_width) / 2.0;
	win->max_width = (win->max_width + win->x_midpoint) / 2.0;
	win->min_width = (win->min_width + win->x_midpoint) / 2.0;
	win->y_midpoint = (win->min_height + win->max_height) / 2.0;
	win->max_height = (win->max_height + win->y_midpoint) / 2.0;
	win->min_height = (win->min_height + win->y_midpoint) / 2.0;
	win->pixel_width = (win->max_width - win->min_width) / win->window_width;
	win->pixel_height = (win->max_height - win->min_height) / win->window_height;
	p->movement_factor *= 2;
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
	win->max_width = (win->max_width + z.r) / 2;
	win->min_width = (win->min_width + z.r) / 2;
	win->max_height = (win->max_height + z.i) / 2;
	win->min_height = (win->min_height + z.i) / 2;
	win->pixel_width = (win->max_width - win->min_width) / win->window_width;
	win->pixel_height = (win->max_height - win->min_height) / win->window_height;
	p->movement_factor *= 2;
	paint_pattern(app);
}

