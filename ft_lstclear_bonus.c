/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:11:11 by obelkhad          #+#    #+#             */
/*   Updated: 2021/11/15 10:01:53 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (lst && del)
	{
		while (*lst)
		{
			current = (*lst);
			(*lst) = (*lst)->next;
			ft_lstdelone(current, del);
		}
	}
	(*lst) = NULL;
}
