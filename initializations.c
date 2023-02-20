/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:15 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/20 07:04:27 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/src/libft.h"
#include "fractol.h"

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
	else if (!ft_strncmp(set_name, "burningship", ft_strlen("burningship")))
		set->set_type = BURNINGSHIP;
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
	fb->buffer = mlx_get_data_addr(app->img, &fb->pixel_bits, &fb->line_bytes,
			&fb->endian);
	return (fb);
}

static t_flags	*init_flags(t_args *args, t_params *p)
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
	if (!args->param_count)
		flags->mouse_one_down = 1;
	else
	{
		flags->mouse_one_down = 0;
		p->set->c.r = args->pos_one;
		p->set->c.i = args->pos_two;
	}
	return (flags);
}

t_app	*init_app(t_params *p, t_args *args)
{
	t_app		*app;
	t_window	*win;
	t_flags		*flags;

	win = p->window_params;
	app = malloc(sizeof(t_app));
	if (!app)
		return (NULL);
	ft_bzero(app, sizeof(t_app));
	app->params = p;
	app->params->args = args;
	flags = init_flags(p->args, p);
	if (!flags)
		return (NULL);
	app->flags = flags;
	app->draw_text = 1;
	app->mlx = mlx_init();
	app->img = mlx_new_image(app->mlx, win->window_width, win->window_height);
	app->win = mlx_new_window(app->mlx, win->window_width, win->window_height,
			"fractol");
	return (app);
}

t_window	*init_window(int h, int w)
{
	t_window	*win;

	win = malloc(sizeof(t_window));
	if (!win)
		return (NULL);
	win->max_width = STARTING_VIEW;
	win->min_width = -STARTING_VIEW;
	win->max_height = STARTING_VIEW;
	win->min_height = -STARTING_VIEW;
	win->window_height = abs(h);
	win->window_width = abs(w);
	win->pixel_width = (win->max_width - win->min_width) / win->window_width;
	win->pixel_height = (win->max_height - win->min_height)
		/ win->window_height;
	return (win);
}

t_params	*init_params(int h, int w, t_set *set)
{
	t_params	*params;

	params = malloc(sizeof(t_params));
	if (!params)
		return (NULL);
	ft_bzero(params, sizeof(t_params));
	params->window_params = init_window(w, h);
	if (!params->window_params)
	{
		free(params);
		return (NULL);
	}
	params->movement_factor = 1;
	params->iter_max = STARTING_ITERATIONS;
	params->set = set;
	return (params);
}
