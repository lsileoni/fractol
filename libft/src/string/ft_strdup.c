/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:53:52 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/03 15:56:15 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned char	*p;
	unsigned char	*tmp;
	int				i;

	p = malloc(ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	tmp = (unsigned char *)s1;
	i = 0;
	while (*tmp)
	{
		*p = *tmp;
		tmp++;
		p++;
		i++;
	}
	*p = '\0';
	return ((char *)p - i);
}
