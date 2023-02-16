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
	t_app		*app;
	t_window	*win;

	win = p->window_params;
	app = malloc(sizeof(t_app));
	if (!app)
		return (NULL);
	app->draw_text = 1;
	app->mlx = mlx_init();
	app->img = mlx_new_image(app->mlx, win->window_width, win->window_height);
	app->win = mlx_new_window(app->mlx, win->window_width, win->window_height, "fractol");
	app->params = p;
	return (app);
}

t_window	*init_window(int h, int w)
{
	t_window	*win;
	
	win = malloc(sizeof(t_window));
	if (!win)
		return (NULL);
	win->max_width = 1.0;
	win->min_width = -1.0;
	win->max_height = 1.0;
	win->min_height = -1.0;
	win->window_height = abs(h);
	win->window_width = abs(w);
	win->pixel_width = (win->max_width - win->min_width) / win->window_width;
	win->pixel_height = (win->max_height - win->min_height) / win->window_height;
	return (win);
}

t_params	*init_params(int h, int w)
{
	t_params	*params;
	params = malloc(sizeof(t_params));
	if (!params)
		return (NULL);
	params->window_params = init_window(h, w);
	if (!params->window_params)
	{
		free(params);
		return (NULL);
	}
	params->movement_factor = 1;
	params->iter_max = 52;
	params->mouse_x = 0;
	params->mouse_y = 0;
	params->mouse_y = 0;
	return (params);
}
