#include "fractol.h"

typedef void (*t_fp)(int key, t_app *app, t_window *win);

static void	assign_functions(t_fp *functions)
{
	functions[ESC] = handle_escape;
	functions[LEFT_ARROW] = keyboard_movement;
	functions[RIGHT_ARROW] = keyboard_movement;
	functions[UP_ARROW] = keyboard_movement;
	functions[DOWN_ARROW] = keyboard_movement;
	functions[I_KEY] = handle_modifiers;
	functions[Z_KEY] = keyboard_movement;
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
		functions[key](key, app, app->params->window_params);
}
