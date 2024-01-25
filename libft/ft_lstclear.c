/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:11:45 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/08 21:57:28 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;
	t_list	*p;

	if (!lst || !del)
	{
		return ;
	}
	p = *lst;
	while (p)
	{
		t = p->next;
		(del)(p->content);
		free (p);
		p = t;
	}
	*lst = NULL;
}
