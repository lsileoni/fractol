/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:54:28 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/07 05:25:47 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*alloc_string(char const *s, unsigned int start, size_t *len)
{
	char	*p;

	if (start >= ft_strlen(s))
	{
		p = malloc(1);
		*len = 0;
	}
	else
	{
		if (ft_strlen(s) >= *len)
			p = malloc(*len + 1);
		else
			p = malloc(ft_strlen(s) + 1);
	}
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (s)
	{
		str = alloc_string(s, start, &len);
		if (!str)
			return (NULL);
		i = 0;
		while (len-- && s[i + start])
		{
			str[i] = s[i + start];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
