#include "fractol.h"

void	handle_escape(int key, t_app *app)
{
	key = 0;
	app = NULL;

	exit(0);
}

void	keyboard_movement(int key, t_app *app)
{
	if (key == Z_KEY)
		zoom_out_static(app);
	if (key == UP_ARROW)
	{
		app->params->max_height -= 0.1 / app->params->movement_factor;
		app->params->min_height -= 0.1 / app->params->movement_factor;
	}
	if (key == DOWN_ARROW)
	{
		app->params->max_height += 0.1 / app->params->movement_factor;
		app->params->min_height += 0.1 / app->params->movement_factor;
	}
	if (key == RIGHT_ARROW)
	{
		app->params->min_width += 0.1 / app->params->movement_factor;
		app->params->max_width += 0.1 / app->params->movement_factor;
	}
	if (key == LEFT_ARROW)
	{
		app->params->min_width -= 0.1 / app->params->movement_factor;
		app->params->max_width -= 0.1 / app->params->movement_factor;
	}
	paint_pattern(app);
}

void	handle_modifiers(int key, t_app *app)
{
	if (key == I_KEY)
		app->params->iter_max += 1;
	if (key == H_KEY)
		app->draw_text *= -1;
	if (key == C_KEY)
		app->params->color_scheme++;
	if (key == R_KEY)
	{
		app->params->max_width = 1.0;
		app->params->min_width = -1.0;
		app->params->max_height = 1.0;
		app->params->min_height = -1.0;
		app->params->movement_factor = 1.0;
	}
	paint_pattern(app);
}
