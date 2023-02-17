#include "fractol.h"

static void	reset_view(t_app *app, t_window *win)
{
	win->max_width = 2.5;
	win->min_width = -2.5;
	win->max_height = 2.5;
	win->min_height = -2.5;
	app->params->movement_factor = 1.0;
	app->params->iter_max = 50;
	win->pixel_width = (win->max_width - win->min_width) / win->window_width;
	win->pixel_height = (win->max_height - win->min_height) / win->window_height;
}

void	check_modifier_actions(t_app *app, t_window *win, unsigned char *key_down_flags)
{
	if (key_down_flags[I_KEY])
	{
		app->params->iter_max += 1;
		paint_pattern(app);
	}
	if (key_down_flags[Z_KEY])
	{
		zoom_in_static(app->params);
		paint_pattern(app);
	}
	if (key_down_flags[C_KEY])
	{
		app->params->color_scheme++;
		paint_pattern(app);
	}
	if (key_down_flags[R_KEY])
	{
		reset_view(app, win);
		paint_pattern(app);
	}
	if (key_down_flags[H_KEY])
	{
		app->draw_text *= -1;
		paint_pattern(app);
	}
}

void	check_movement_actions(t_app *app, t_window	*win, unsigned char *key_down_flags)
{
	if (key_down_flags[LEFT_ARROW])
	{
		win->min_width -= 0.1 / app->params->movement_factor;
		win->max_width -= 0.1 / app->params->movement_factor;
		paint_pattern(app);
	}
	if (key_down_flags[RIGHT_ARROW])
	{
		win->min_width += 0.1 / app->params->movement_factor;
		win->max_width += 0.1 / app->params->movement_factor;
		paint_pattern(app);
	}
	if (key_down_flags[UP_ARROW])
	{
		win->max_height -= 0.1 / app->params->movement_factor;
		win->min_height -= 0.1 / app->params->movement_factor;
		paint_pattern(app);
	}
	if (key_down_flags[DOWN_ARROW])
	{
		win->max_height += 0.1 / app->params->movement_factor;
		win->min_height += 0.1 / app->params->movement_factor;
		paint_pattern(app);
	}
}

void	check_mouse_actions(t_app *app)
{
	t_flags		*flags;

	flags = app->flags;
	if (app->flags->scroll_up)
	{
		zoom_in_complex(app, app->params->mouse_x, app->params->mouse_y);
	}
	if (app->flags->scroll_down)
	{
		zoom_out_static(app);
	}
}
