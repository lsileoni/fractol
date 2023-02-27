/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:32:24 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/27 21:06:14 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_to_lowercase(char *str)
{
	char	*storage;
	int		i;

	if (!str)
		return (NULL);
	storage = malloc(ft_strlen(str) + 1);
	if (!storage)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				storage[i] = ft_tolower(str[i]);
			else
				storage[i] = str[i];
		}
		else
			storage[i] = str[i];
		i++;
	}
	storage[i] = '\0';
	return (storage);
}

char	*ft_to_uppercase(char *str)
{
	char	*storage;
	int		i;

	if (!str)
		return (NULL);
	storage = malloc(ft_strlen(str) + 1);
	if (!storage)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				storage[i] = ft_toupper(str[i]);
			else
				storage[i] = str[i];
		}
		else
			storage[i] = str[i];
		i++;
	}
	storage[i] = '\0';
	return (storage);
}

char	*ft_uitoa_base(unsigned int n, unsigned char base)
{
	char			storage[17];
	const char		char_to_int[] = "0123456789abcdef";
	unsigned int	i;
	int				j;

	if (!n)
		return (ft_strdup("0"));
	i = n;
	j = 0;
	while (i)
	{
		i /= base;
		j++;
	}
	j--;
	i = j + 1;
	while (n)
	{
		storage[j] = char_to_int[n % base];
		n /= base;
		j--;
	}
	storage[i] = '\0';
	return (ft_strdup(&storage[0]));
}

char	*ft_ulltoa_base(unsigned long long n, unsigned char base)
{
	char				storage[17];
	const char			char_to_int[] = "0123456789abcdef";
	unsigned long long	i;
	int					j;

	if (!n)
		return (ft_strdup("0"));
	i = n;
	j = 0;
	while (i)
	{
		i /= base;
		j++;
	}
	j--;
	i = j + 1;
	while (n)
	{
		storage[j] = char_to_int[n % base];
		n /= base;
		j--;
	}
	storage[i] = '\0';
	return (ft_strdup(&storage[0]));
}
