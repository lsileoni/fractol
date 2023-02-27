/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_uppercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:40:12 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/27 17:40:13 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
