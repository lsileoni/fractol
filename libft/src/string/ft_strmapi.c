/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:54:12 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/03 17:57:58 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	*p;
	size_t			i;

	if (!s || !f)
		return (NULL);
	p = malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return ((char *)p);
}
