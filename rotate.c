/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:48:56 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/31 13:04:03 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p && p->next)
	{
		tmp = p->next;
		ft_stack_last(*stack_a)->next = p;
		p->next = NULL;
		*stack_a = tmp;
		ft_printf(1, "ra\n");
	}
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_b;
	if (p && p->next)
	{
		tmp = p->next;
		ft_stack_last(*stack_b)->next = p;
		p->next = NULL;
		*stack_b = tmp;
		ft_printf(1, "rb\n");
	}
}

// rr : ra and rb at the same time.

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p && p->next)
	{
		tmp = p->next;
		ft_stack_last(*stack_a)->next = p;
		p->next = NULL;
		*stack_a = tmp;
	}
	p = *stack_b;
	if (p && p->next)
	{
		tmp = p->next;
		ft_stack_last(*stack_b)->next = p;
		p->next = NULL;
		*stack_b = tmp;
	}
	ft_printf(1, "rr\n");
}
