#include "fractol.h"

void	handle_escape(int key, t_app *app, t_window *win)
{
	win = 0;
	key = 0;
	app = NULL;

	exit(0);
}

void	keyboard_movement(int key, t_app *app, t_window *win)
{
	if (key == Z_KEY)
		zoom_in_static(app->params);
	if (key == UP_ARROW)
	{
		win->max_height -= 0.1 / app->params->movement_factor;
		win->min_height -= 0.1 / app->params->movement_factor;
	}
	if (key == DOWN_ARROW)
	{
		win->max_height += 0.1 / app->params->movement_factor;
		win->min_height += 0.1 / app->params->movement_factor;
	}
	if (key == RIGHT_ARROW)
	{
		win->min_width += 0.1 / app->params->movement_factor;
		win->max_width += 0.1 / app->params->movement_factor;
	}
	if (key == LEFT_ARROW)
	{
		win->min_width -= 0.1 / app->params->movement_factor;
		win->max_width -= 0.1 / app->params->movement_factor;
	}
	paint_pattern(app);
}

void	handle_modifiers(int key, t_app *app, t_window *win)
{
	win = 0;
	if (key == I_KEY)
		app->params->iter_max += 1;
	if (key == H_KEY)
		app->draw_text *= -1;
	if (key == C_KEY)
		app->params->color_scheme++;
	if (key == R_KEY)
	{
		win->max_width = 1.0;
		win->min_width = -1.0;
		win->max_height = 1.0;
		win->min_height = -1.0;
		app->params->movement_factor = 1.0;
	}
	paint_pattern(app);
}
