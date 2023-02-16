#include "fractol.h"

typedef void (*t_fp)(int key, t_app *app);

static void	handle_movement(int key, t_app *app)
{
	if (key == UP_ARROW)
		app->flags->up_arrow = 1;
	if (key == DOWN_ARROW)
		app->flags->down_arrow = 1;
	if (key == RIGHT_ARROW)
		app->flags->right_arrow = 1;
	if (key == LEFT_ARROW)
		app->flags->left_arrow= 1;
}

static void	handle_modifiers(int key, t_app *app)
{
	if (key == ESC)
		app->flags->esc = 1;
	if (key == I_KEY)
		app->flags->i_key = 1;
	if (key == H_KEY)
		app->flags->h_key = 1;
	if (key == C_KEY)
		app->flags->c_key = 1;
	if (key == R_KEY)
		app->flags->r_key = 1;
	if (key == Z_KEY)
		app->flags->z_key = 1;
}

static void	assign_functions(t_fp *functions)
{
	functions[ESC] = handle_modifiers;
	functions[LEFT_ARROW] = handle_movement;
	functions[RIGHT_ARROW] = handle_movement;
	functions[UP_ARROW] = handle_movement;
	functions[DOWN_ARROW] = handle_movement;
	functions[I_KEY] = handle_modifiers;
	functions[Z_KEY] = handle_movement;
	functions[C_KEY] = handle_modifiers;
	functions[H_KEY] = handle_modifiers;
	functions[R_KEY] = handle_modifiers;
}

static int	valid_key(int key)
{
	static int	key_values[] = {ESC, LEFT_ARROW, UP_ARROW, DOWN_ARROW, RIGHT_ARROW, I_KEY, Z_KEY, C_KEY, H_KEY, R_KEY};
	int			i;

	i = 0;
	while (i < KEY_COUNT)
	{
		if (key == key_values[i])
			return (1);
		i++;
	}
	return (0);
}

void	switchboard(int key, t_app *app)
{
	static t_fp	functions[127];

	assign_functions(functions);
	if (valid_key(key))
		functions[key](key, app);
}
