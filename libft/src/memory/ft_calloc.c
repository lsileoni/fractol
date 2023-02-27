/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:52:13 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/13 16:38:20 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	if (!count || !size)
		return (ft_calloc(1, 1));
	i = count * size;
	if (i / count != size)
		return (NULL);
	p = malloc(i);
	if (p)
	{
		ft_bzero(p, i);
		return (p);
	}
	return (NULL);
}
