/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:00 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/20 06:59:20 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/src/libft.h"
#include "fractol.h"
#include "minilibx_opengl/mlx.h"

int	render_frame(t_app *app)
{
	unsigned char	mouse_one_down;
	unsigned char	*key_down;

	key_down = app->flags->key_down_flags;
	mouse_one_down = app->flags->mouse_one_down;
	if (key_down[ESC])
	{
		mlx_destroy_image(app->mlx, app->img);
		mlx_destroy_window(app->mlx, app->win);
		free(key_down);
		free(app->params->window_params);
		free(app->params->set);
		free(app->params);
		free(app->fb);
		free(app->flags);
		free(app);
		exit(0);
		return (0);
	}
	check_mouse_actions(app);
	check_modifier_actions(app, app->params->window_params, key_down);
	check_movement_actions(app, app->params->window_params, key_down);
	ft_bzero(app->flags, sizeof(t_flags));
	app->flags->key_down_flags = key_down;
	app->flags->mouse_one_down = mouse_one_down;
	return (0);
}

void	define_hooks(t_app *app)
{
	mlx_hook(app->win, 2, 1L << 0, key_down, app);
	mlx_hook(app->win, 3, 1L << 0, key_up, app);
	mlx_hook(app->win, 4, 1L << 0, mouse_hook, app);
	mlx_hook(app->win, 6, 1L << 0, mouse_movement_hook, app);
	mlx_hook(app->win, 17, 1L << 0, close_window, app);
	mlx_loop_hook(app->mlx, render_frame, app);
}

int	main(int argc, char **argv)
{
	t_app			*app;
	t_set			*set;
	t_params		*params;
	t_framebuffer	*fb;
	t_args			*args;

	args = malloc(sizeof(t_args));
	set = argument_parser(argc, argv, args);
	if (!(set))
	{
		if (args)
			free(args);
		exit(1);
	}
	params = init_params(args->x, args->y, set);
	if (!(params))
	{
		free(set);
		free(args);
		exit(1);
	}
	app = init_app(params, args);
	if (!(app))
	{
		free(set);
		free(args);
		free(params);
		exit(1);
	}
	fb = init_framebuffer(app);
	if (!(fb))
	{
		free(params);
		free(set);
		free(app);
	}
	app->fb = fb;
	define_hooks(app);
	paint_pattern(app);
	mlx_loop(app->mlx);
	return (0);
}
