/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 07:00:52 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/20 07:01:17 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./libft/src/libft.h"

static void	check_six(t_args *args, t_set *set, char **argv)
{
	args->param_count = 6;
	if (set->set_type == JULIA)
	{
		args->pos_one = ft_atod(argv[2]);
		args->pos_two = ft_atod(argv[3]);
		args->x = ft_atoi(argv[4]);
		args->y = ft_atoi(argv[5]);
	}
	else
		printf("A parameter count of 4 only works with a Julia set\n");
}

static void	check_four(t_args *args, t_set *set, char **argv)
{
	args->param_count = 2;
	if (set->set_type == JULIA)
	{
		args->pos_one = ft_atod(argv[2]);
		args->pos_two = ft_atod(argv[3]);
		args->x = 500;
		args->y = 500;
	}
	else
	{
		args->x = ft_atoi(argv[2]);
		args->y = ft_atoi(argv[3]);
	}
}

static t_set	*check_two_up(t_args *args, char **argv, int argc)
{
	t_set	*set;

	set = init_set(argv[1]);
	if (!(set))
	{
		free(args);
		return (NULL);
	}
	if (argc == 2)
	{
		args->x = 500;
		args->y = 500;
	}
	else if (argc == 4)
		check_four(args, set, argv);
	else if (argc == 6)
		check_six(args, set, argv);
	else
	{
		ft_printf("Invalid number of parameters!\n");
		return (NULL);
	}
	return (set);
}

t_set	*argument_parser(int argc, char **argv, t_args *args)
{
	t_set	*set;

	set = NULL;
	if (!args)
		return (NULL);
	args->param_count = 0;
	if (argc < 2)
	{
		ft_printf("Not enough arguments given!\n");
		return (NULL);
	}
	set = check_two_up(args, argv, argc);
	return (set);
}
