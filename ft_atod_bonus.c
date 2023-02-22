/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:42:50 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/22 22:27:35 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	is_negative(const char *str)
{
	while (*str != '-' && *str != '+' && !ft_isdigit(*str) && *str)
		str++;
	if (*str == '-')
		return (1);
	return (0);
}

double	ft_atod(char *str)
{
	double			left;
	double			right;
	int				neg;
	unsigned char	error;

	error = 0;
	left = parse_left(str, &error);
	right = parse_right(str, &error);
	if (error == 1)
		ft_printf("A floating point value provided was wrong!\n");
	if (error == 2)
		perror("A memory allocation issue has occured!\n");
	if (error)
		exit(1);
	neg = is_negative(str);
	if (!left)
	{
		if (neg)
			return ((left + right) * -1.0);
		return (left + right);
	}
	if (neg)
		return ((left + right) * -1.0);
	return (left + right);
}
