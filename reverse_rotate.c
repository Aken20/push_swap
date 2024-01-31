/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:49:37 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/31 06:14:59 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_b_stack_last(t_stack *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a->next->next != NULL)
		stack_a = stack_a->next;
	return (stack_a);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

void	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p->next)
	{
		tmp = ft_stack_last(*stack_a);
		ft_b_stack_last(*stack_a)->next = NULL;
		tmp->next = p;
		*stack_a = tmp;
	}
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

void	rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_b;
	if (p->next)
	{
		tmp = ft_stack_last(*stack_b);
		ft_b_stack_last(*stack_b)->next = NULL;
		tmp->next = p;
		*stack_b = tmp;
	}
}

// rrr : rra and rrb at the same time.

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rra(stack_b);
}