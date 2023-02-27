/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:51:43 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/07 05:31:42 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static int	overflow_return(int is_neg)
{
	if (is_neg)
		return (0);
	return (-1);
}

static int	integer_return(int is_neg, long long res)
{
	if (is_neg)
		return (res * -1);
	return (res);
}

int	ft_atoi(const char *str)
{
	int			is_neg;
	long long	res;

	is_neg = 0;
	res = 0;
	if (*str)
	{
		while (is_whitespace(*str))
			str++;
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				is_neg = 1;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			res = (res * 10) + (*str - '0');
			str++;
			if (res < 0)
				return (overflow_return(is_neg));
		}
		return (integer_return(is_neg, res));
	}
	return (0);
}
