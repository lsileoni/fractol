/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:00 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/19 22:26:02 by lsileoni         ###   ########.fr       */
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

double	*split_to_double(char **strs)
{
	double	*ret;
	int		count;
	double	neg;

	count = 0;
	neg = 1.0;
	while (strs[count])
		count++;
	if (count != 2)
		return (NULL);
	ret = malloc(sizeof(double));
	if (!ret)
		return (NULL);
	if (ft_strlen(strs[0]) != 1 || ft_strlen(strs[1]) != 1)
	{
		free(ret);
		return (NULL);
	}
	*ret = 0;
	*ret += ft_atoi(strs[0]);
	if (*ret < 0)
	{
		*ret = fabs(*ret);
		neg = -1.0;
	}
	*ret += ft_atoi(strs[1]) / 10.0;
	*ret *= neg;
	return (ret);
}

double	*julia_parsed(char *one, char *two)
{
	double	*tuple;
	char	**strs;
	double	*tmp;

	tuple = malloc(sizeof(double) * 2);
	if (!tuple)
		return (NULL);
	strs = ft_split(one, '.');
	if (!strs)
		return (NULL);
	tmp = split_to_double(strs);
	if (!tmp)
		return (NULL);
	tuple[0] = *tmp;
	free(tmp);
	strs = ft_split(two, '.');
	if (!strs)
		return (NULL);
	tmp = split_to_double(strs);
	if (!tmp)
		return (NULL);
	tuple[1] = *tmp;
	free(tmp);
	return (tuple);
}

t_set	*argument_parser(int argc, char **argv, t_args *args)
{
	t_set	*set;
	double	*tmp;

	set = NULL;
	if (!args)
		return (NULL);
	args->param_count = 0;
	if (argc < 2)
	{
		ft_printf("Not enough arguments given!\n");
		return (NULL);
	}
	if (argc >= 2)
	{
		if (!(set = init_set(argv[1])))
		{
			free(args);
			return (NULL);
		}
		if (argc == 2)
		{
			args->x = 750;
			args->y = 750;
		}
		else if (argc == 4)
		{
			args->param_count = 2;
			if (set->set_type == JULIA)
			{
				tmp = julia_parsed(argv[2], argv[3]);
				if (!tmp)
				{
					free(set);
					free(args);
					return (NULL);
				}
				args->pos_one = tmp[0];
				args->pos_two = tmp[1];
				free(tmp);
				args->x = 750;
				args->y = 750;
			}
			else
			{
				args->x = ft_atoi(argv[2]);
				args->y = ft_atoi(argv[3]);
			}
		}
		else if (argc == 6)
		{
			args->param_count = 6;
			if (set->set_type == JULIA)
			{
				tmp = julia_parsed(argv[2], argv[3]);
				if (!tmp)
				{
					free(set);
					free(args);
					return (NULL);
				}
				args->pos_one = tmp[0];
				args->pos_two = tmp[1];
				free(tmp);
				args->x = ft_atoi(argv[2]);
				args->y = ft_atoi(argv[3]);
			}
			else
			{
				printf("A parameter count of 4 only works with a Julia set\n");
				return (NULL);
			}
		}
		else
		{
			ft_printf("Invalid number of parameters!\n");
			return (NULL);
		}
	}
	return (set);
}

int	main(int argc, char **argv)
{
	t_app			*app;
	t_set			*set;
	t_params		*params;
	t_framebuffer	*fb;
	t_args			*args;

	args = malloc(sizeof(t_args));
	if (!(set = argument_parser(argc, argv, args)))
	{
		free(args);
		exit(1);
	}
	if (!(params = init_params(args->x, args->y, set)))
	{
		free(set);
		free(args);
		exit(1);
	}
	if (!(app = init_app(params, args)))
	{
		free(set);
		free(args);
		free(params);
		exit(1);
	}
	if (!(fb = init_framebuffer(app)))
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
