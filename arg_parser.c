/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 07:00:52 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/20 10:22:00 by lsileoni         ###   ########.fr       */
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
		ft_printf("A parameter count of 4 only works with a Julia set\n");
}

static void	check_four(t_args *args, t_set *set, char **argv)
{
	args->param_count = 2;
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
		args->x = 650;
		args->y = 650;
	}
	else if (argc == 4)
		check_four(args, set, argv);
	else if (argc == 6)
		check_six(args, set, argv);
	else
	{
		ft_printf("Invalid number of parameters!\n");
		return (0);
	}
	return (1);
}

int	argument_parser(int argc, char **argv, t_args *args, t_set *set)
{
	if (!args || !set || !argv)
		return (0);
	args->param_count = 0;
	if (argc < 2)
	{
		ft_printf("Program usage\n-------------------------\n");
		ft_printf("Static fractals: ./fractol  {mandelbrot/burningship}");
		ft_printf(" \t\t{optional x and y resolution}\n");
		ft_printf("Dynamic fractals: ./fractol {julia} {optional r and i coords}");
		ft_printf("   {optional x and y resolution}\n");
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
