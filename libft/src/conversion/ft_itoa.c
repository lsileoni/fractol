/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:52:45 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/07 05:01:08 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_strrev(char *str)
{
	int		str_size;
	int		i;
	char	*p;

	str_size = ft_strlen(str);
	p = malloc(str_size + 1);
	if (!p)
		return (NULL);
	i = 0;
	str_size--;
	while (str_size >= 0)
	{
		p[i] = str[str_size];
		str_size--;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	int			is_neg;
	char		str[12];
	long int	n_long;

	if (!n)
		return (ft_strdup("0"));
	is_neg = 0;
	n_long = n;
	if (n_long < 0)
	{
		is_neg = 1;
		n_long *= -1;
	}
	n = 0;
	while (n_long)
	{
		str[n++] = (n_long % 10) + 48;
		n_long /= 10;
	}
	if (is_neg)
		str[n] = '-';
	str[n + is_neg] = '\0';
	return (ft_strrev(str));
}
