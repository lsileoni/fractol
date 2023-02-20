/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:42:50 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/20 07:01:48 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/src/libft.h"
#include <stdio.h>
#include <math.h>

static int	leftlen(const char *str)
{
	int	res;
	int	len;

	res = 0;
	len = 0;
	while (*str)
	{
		if (*str == '.')
		{
			res = len;
			break ;
		}
		len++;
		str++;
	}
	return (res);
}

static double	parse_left(const char *str)
{
	double			ret;
	char			*left;
	unsigned int	malloc_size;
	unsigned int	i;

	while (*str != '-' && *str != '+' && !ft_isdigit(*str) && *str)
		str++;
	malloc_size = leftlen(str);
	left = malloc(malloc_size + 1);
	i = 0;
	while (str[i] != '.')
	{
		left[i] = str[i];
		i++;
	}
	left[i] = '\0';
	ret = (double)ft_atoi(left);
	free(left);
	return (ret);
}

static double	parse_right(const char *str)
{
	double				ret;
	char				*right;
	unsigned int		i;

	while (*str != '.')
		str++;
	str++;
	i = 0;
	while (str[i])
		i++;
	right = malloc(i + 1);
	i = 0;
	while (str[i])
	{
		right[i] = str[i];
		i++;
	}
	right[i] = '\0';
	ret = ((double)ft_atoi(right)) / (pow(10, i));
	free(right);
	return (ret);
}

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
	double	left;
	double	right;
	int		neg;

	left = parse_left(str);
	right = parse_right(str);
	neg = is_negative(str);
	if (left < 0.0)
		return (left - right);
	if (!left)
	{
		if (neg)
			return ((left + right) * -1.0);
		return (left + right);
	}
	if (neg)
		return (left - right);
	return (left + right);
}
