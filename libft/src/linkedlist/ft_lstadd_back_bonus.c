/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:52:48 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/02 18:57:34 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *_new)
{
	t_list	*last_node;

	if (lst)
	{
		if (*lst)
		{
			last_node = ft_lstlast(*lst);
			if (last_node)
				last_node->next = _new;
		}
		else
		{
			*lst = _new;
		}
	}
}
