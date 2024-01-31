/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:11:57 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/31 06:43:36 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_b;
	if (p)
	{
		tmp = p->next;
        p = tmp;
		p->next = *stack_a;
        *stack_a = p;
		// tmp->next = tmp;
		p = tmp;
	}
}


