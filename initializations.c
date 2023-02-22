/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:15 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/22 22:16:29 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_set(char *set_name, t_set *set)
{
	ft_bzero(set, sizeof(t_set));
	if (!ft_strncmp(set_name, "mandelbrot", ft_strlen("mandelbrot")))
		set->set_type = MANDELBROT;
	else if (!ft_strncmp(set_name, "julia", ft_strlen("julia")))
		set->set_type = JULIA;
	else
		return (0);
	return (1);
}

static t_flags	*init_flags(t_args *args, t_params *p)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
	{
		perror("Failed to allocate key_down_flags!\n");
		return (NULL);
	}
	ft_bzero(flags, sizeof(t_flags));
	flags->key_down_flags = malloc(KEY_RANGE + 1);
	if (!flags->key_down_flags)
	{
		perror("Failed to allocate key_down_flags!\n");
		free(flags);
		return (NULL);
	}
	ft_bzero(flags->key_down_flags, KEY_RANGE + 1);
	p->set->c.r = args->pos_one;
	p->set->c.i = args->pos_two;
	return (flags);
}

int	init_app(t_params *p, t_args *args, t_app *app)
{
	t_window	*win;
	t_flags		*flags;

	win = p->window_params;
	ft_bzero(app, sizeof(t_app));
	app->params = p;
	app->params->args = args;
	flags = init_flags(p->args, p);
	if (!flags)
		return (0);
	app->flags = flags;
	app->mlx = mlx_init();
	app->img = mlx_new_image(app->mlx, win->window_width, win->window_height);
	app->win = mlx_new_window(app->mlx, win->window_width, win->window_height,
			"fractol");
	if (!app->mlx || !app->img || !app->win)
	{
		ft_printf("mlx failed to initialize!\n");
		return (0);
	}
	return (1);
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

int	init_params(int window_width, int window_height, \
				t_set *set, t_params *params)
{
	ft_bzero(params, sizeof(t_params));
	params->window_params = init_window(window_height, window_width);
	if (!params->window_params)
		return (0);
	params->movement_factor = 1;
	params->iter_max = STARTING_ITERATIONS;
	params->set = set;
	return (1);
}
