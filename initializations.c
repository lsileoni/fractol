#include "fractol.h"
#include "./libft/src/libft.h"

static void	setzero(t_set *set)
{
	set->z.r = 0;
	set->z.i = 0;
	set->z_s.r = 0;
	set->z_s.i = 0;
	set->c.r = 0;
	set->c.i = 0;
}

t_set	*init_set(char *set_name)
{
	t_set	*set;

	if (!set_name)
		return (NULL);

	set = malloc(sizeof(t_set));
	if (!set)
		return (NULL);
	if (!ft_strncmp(set_name, "mandelbrot", ft_strlen("mandelbrot")))
		set->set_type = MANDELBROT;
	else if (!ft_strncmp(set_name, "julia", ft_strlen("julia")))
		set->set_type = JULIA;
	else if (!ft_strncmp(set_name, "thorn", ft_strlen("thorn")))
		set->set_type = THORN;
	else
	{
		free(set);
		return (NULL);
	}
	setzero(set);
	return (set);
}

t_framebuffer	*init_framebuffer(t_app *app)
{
	t_framebuffer	*fb;

	fb = malloc(sizeof(t_framebuffer));
	if (!fb || !app)
		return (NULL);
	fb->buffer = NULL;
	fb->line_bytes = 0;
	fb->pixel_bits = 0;
	fb->pixel = 0;
	fb->endian = 0;
	fb->buffer = mlx_get_data_addr(app->img, &fb->pixel_bits, &fb->line_bytes, &fb->endian);
	return (fb);
}

t_app	*init_app(t_params *p)
{
	t_app	*app;

	app = malloc(sizeof(t_app));
	if (!app)
		return (NULL);
	app->draw_text = 1;
	app->mlx = mlx_init();
	app->img = mlx_new_image(app->mlx, p->window_width, p->window_height);
	app->win = mlx_new_window(app->mlx, p->window_width, p->window_height, "SEIS");
	app->params = p;
	return (app);
}

t_params	*init_params(int h, int w)
{
	t_params	*params;
	params = malloc(sizeof(t_params));
	if (!params)
		return (NULL);
	params->max_width = 1.0;
	params->min_width = -1.0;
	params->max_height = 1.0;
	params->min_height = -1.0;
	params->movement_factor = 1;
	params->iter_max = 52;
	params->mouse_x = 0;
	params->mouse_y = 0;
	params->mouse_y = 0;
	params->window_height = h;
	params->window_width = w;
	params->pixel_width = (params->max_width - params->min_width) / params->window_width;
	params->pixel_height = (params->max_height - params->min_height) / params->window_height;
	return (params);
}
