/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 07:00:52 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/22 22:15:26 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_six(t_args *args, t_set *set, char **argv)
{
	if (set->set_type == JULIA)
	{
		args->pos_one = ft_atod(argv[2]);
		args->pos_two = ft_atod(argv[3]);
		args->x = ft_atoi(argv[4]);
		args->y = ft_atoi(argv[5]);
		return (1);
	}
	else
	{
		ft_printf("A parameter count of 4 only works with a Julia set\n");
		return (0);
	}
}

static void	check_four(t_args *args, t_set *set, char **argv)
{
	if (set->set_type == JULIA)
	{
		args->pos_one = ft_atod(argv[2]);
		args->pos_two = ft_atod(argv[3]);
		args->x = 650;
		args->y = 650;
	}
	else
	{
		args->x = ft_atoi(argv[2]);
		args->y = ft_atoi(argv[3]);
	}
}

static int	check_two_up(t_args *args, char **argv, int argc, t_set *set)
{
	if (argc == 2)
	{
		args->pos_one = 0.0;
		args->pos_two = 0.0;
		args->x = 650;
		args->y = 650;
	}
	else if (argc == 4)
		check_four(args, set, argv);
	else if (argc == 6)
	{
		if (!check_six(args, set, argv))
			return (0);
	}
	else
	{
		ft_printf("Invalid number of parameters!\n");
		return (0);
	}
	return (1);
}

static void	print_help(void)
{
	ft_printf("\nProgram usage\n-------------------------\n");
	ft_printf("Static fractals:  ./fractol {mandelbrot/julia}\n");
	ft_printf("Mandelbrot parameters: {width height}\n");
	ft_printf("Julia parameters: {c.r c.i width height}\n\n");
	ft_printf("Examples\n-------------------------\n");
	ft_printf("./fractol julia 0.8 0.0 800 800\n");
	ft_printf("./fractol mandelbrot 800 800\n");
}

int	argument_parser(int argc, char **argv, t_args *args, t_set *set)
{
	if (!args || !set || !argv)
		return (0);
	if (argc < 2)
	{
		print_help();
		return (0);
	}
	if (!init_set(argv[1], set))
	{
		ft_printf("Set name is wrong!\n");
		return (0);
	}
	if (!check_two_up(args, argv, argc, set))
		return (0);
	if (args->x > 1000)
		args->x = 1000;
	if (args->x < 200)
		args->x = 200;
	if (args->y > 1000)
		args->y = 1000;
	if (args->y < 200)
		args->y = 200;
	return (1);
}
