/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:54:06 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/04 00:14:10 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	rval;

	rval = ft_strlen(src);
	if (!*src)
		return (rval * (*dst = '\0'));
	if (dstsize)
	{
		i = 0;
		while (i < (dstsize - 1) && *src)
		{
			*dst = *src;
			dst++;
			src++;
			i++;
		}
		*dst = '\0';
	}
	return (rval);
}
