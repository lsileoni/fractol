#include "fractol.h"
#include "./libft/src/libft.h"

t_set	*init_set(char *set_name)
{
	t_set	*set;

	if (!set_name)
		return (NULL);
	set = malloc(sizeof(t_set));
	if (!set)
		return (NULL);
	ft_bzero(set, sizeof(t_set));
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
	return (set);
}

t_framebuffer	*init_framebuffer(t_app *app)
{
	t_framebuffer	*fb;

	fb = malloc(sizeof(t_framebuffer));
	if (!fb || !app)
		return (NULL);
	ft_bzero(fb, sizeof(t_framebuffer));
	fb->buffer = mlx_get_data_addr(app->img, &fb->pixel_bits, &fb->line_bytes, &fb->endian);
	return (fb);
}

t_flags	*init_flags(void)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	ft_bzero(flags, sizeof(t_flags));
	flags->key_down_flags = malloc(KEY_RANGE + 100);
	if (!flags->key_down_flags)
	{
		free(flags);
		return (NULL);
	}
	ft_bzero(flags->key_down_flags, KEY_RANGE);
	flags->mouse_one_down = 1;
	return (flags);
}

t_app	*init_app(t_params *p)
{
	t_app		*app;
	t_window	*win;
	t_flags		*flags;

	win = p->window_params;
	app = malloc(sizeof(t_app));
	if (!app)
		return (NULL);
	ft_bzero(app, sizeof(t_app));
	flags = init_flags();
	if (!flags)
		return (NULL);
	app->flags = flags;
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
	win->max_width = 2.5;
	win->min_width = -2.5;
	win->max_height = 2.5;
	win->min_height = -2.5;
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
	ft_bzero(params, sizeof(t_params));
	params->window_params = init_window(h, w);
	if (!params->window_params)
	{
		free(params);
		return (NULL);
	}
	params->movement_factor = 1;
	params->iter_max = 52;
	return (params);
}
