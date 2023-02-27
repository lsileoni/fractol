/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:54:19 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/13 16:10:54 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			needle_len;
	size_t			i;

	needle_len = ft_strlen(needle);
	if (!haystack && !len)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	i = 1;
	while (*haystack && len)
	{
		if ((i + needle_len - 1) > len)
			break ;
		if (!ft_strncmp(needle, haystack, needle_len))
			return ((char *) haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
