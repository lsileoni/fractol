#include "fractol.h"

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

void	switchboard(int key, t_app *app, unsigned char up_down)
{
	if (valid_key(key))
	{
		if (up_down)
			app->flags->key_down_flags[key] = 1;
		else
			app->flags->key_down_flags[key] = 0;
	}
}
