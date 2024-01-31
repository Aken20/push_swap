/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:12:36 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/30 15:48:12 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

void	sa(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p->next)
	{
		tmp = p->next;
		p->next = p->next->next;
		tmp->next = p;
		*stack_a = tmp;
	}
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

void	sb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_b;
	if (p->next)
	{
		tmp = p->next;
		p->next = p->next->next;
		tmp->next = p;
		*stack_b = tmp;
	}
}

// ss : sa and sb at the same time.

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sa(stack_b);
}
