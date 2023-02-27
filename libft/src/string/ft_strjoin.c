/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:53:59 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/07 11:33:08 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*alloc_string(int len)
{
	char	*p;

	p = malloc(len + 1);
	if (!p)
		return (NULL);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		total_size;
	int		s1_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	total_size = s1_len + ft_strlen(s2);
	str = alloc_string(total_size);
	if (!str)
		return (NULL);
	i = 0;
	while (total_size)
	{
		if (i < s1_len)
			str[i] = s1[i];
		else
			str[i] = s2[i - s1_len];
		total_size--;
		i++;
	}
	str[i] = '\0';
	return (str);
}
