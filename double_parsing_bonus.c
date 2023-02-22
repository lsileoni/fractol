/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:24:59 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/22 15:48:06 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./libft/src/libft.h"

static int	leftlen(const char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str == '.')
			return (len);
		if (!ft_isdigit(*str))
			return (0);
		len++;
		str++;
	}
	return (len);
}

static double	get_left_double(const char *str, char *left)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '.' && str[i])
	{
		left[i] = str[i];
		i++;
	}
	left[i] = '\0';
	return ((double)ft_atoi(left));
}

double	parse_left(const char *str, unsigned char *error)
{
	char			*left;
	double			ret;
	unsigned int	malloc_size;

	while (*str != '-' && *str != '+' && !ft_isdigit(*str) && *str)
		str++;
	if (*str == '-' || *str == '+')
		str++;
	malloc_size = leftlen(str);
	if (!malloc_size)
	{
		*error = 1;
		return (0.0);
	}
	left = malloc(malloc_size + 1);
	if (!left)
	{
		*error = 2;
		return (0.0);
	}
	ret = get_left_double(str, left);
	free(left);
	return ((double)ft_atoi(left));
}

static double	get_right_double(const char *str, char *right, \
								unsigned char *error)
{
	unsigned int		i;

	i = 0;
	while (str[i])
	{
		right[i] = str[i];
		if (!ft_isdigit(str[i]))
			*error = 1;
		i++;
	}
	right[i] = '\0';
	return (((double)ft_atoi(right)) / (pow(10, i)));
}

double	parse_right(const char *str, unsigned char *error)
{
	char				*right;
	double				ret;
	unsigned int		i;

	right = NULL;
	while (*str != '.')
		str++;
	str++;
	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (!i)
	{
		*error = 1;
		return (0.0);
	}
	right = malloc(i + 1);
	if (!right)
	{
		*error = 2;
		return (0.0);
	}
	ret = get_right_double(str, right, error);
	free(right);
	return (ret);
}
