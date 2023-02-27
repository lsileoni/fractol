/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:52:55 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/03 17:56:06 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*curr;

	if (!lst || !del)
		return ;
	curr = *lst;
	while (curr->next)
	{
		next = curr->next;
		ft_lstdelone(curr, del);
		curr = next;
	}
	ft_lstdelone(curr, del);
	*lst = NULL;
}
