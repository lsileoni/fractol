#include "fractol.h"

typedef void (*t_fp)(unsigned char c, unsigned int pixel, unsigned char i, char *b);

static void	assign_functions(t_fp *functions)
{
	functions[WHITE_ENERGY] = energy;
	functions[NEON_ENERGY] = energy;
	functions[PINK_ENERGY] = energy;
	functions[BLACK_WHITE] = glow;
	functions[RED_GLOW] = glow;
	functions[GREEN_GLOW] = glow;
	functions[BLUE_GLOW] = glow;
}

int	valid_color(unsigned char color)
{
	static int	color_values[] = {WHITE_ENERGY, NEON_ENERGY, PINK_ENERGY, BLACK_WHITE, RED_GLOW, GREEN_GLOW, BLUE_GLOW};
	int			i;

	i = 0;
	while (i < KEY_COUNT)
	{
		if (color == color_values[i])
			return (1);
		i++;
	}
	return (0);
}

void	colorboard(unsigned char color, unsigned int pixel, unsigned char iterations, char *buffer)
{
	static t_fp	functions[127];

	assign_functions(functions);
	if (valid_color(color % COLOR_SCHEMES))
		functions[color % COLOR_SCHEMES]((color % COLOR_SCHEMES), pixel, iterations, buffer);
}
