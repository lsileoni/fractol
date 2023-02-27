/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:40:01 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/27 17:40:02 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
