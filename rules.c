/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:50:42 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/29 17:03:27 by ahibrahi         ###   ########.fr       */
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

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.



// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p->next)
	{
		tmp = p->next;
		ft_stack_last(*stack_a)->next = p;
		p->next = NULL;
		*stack_a = tmp;
	}
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_b;
	if (p->next)
	{
		tmp = p->next;
		ft_stack_last(*stack_b)->next = p;
		p->next = NULL;
		*stack_b = tmp;
	}
}

// rr : ra and rb at the same time.

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	ra(stack_b);
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
		ft_stack_last(*stack_a)->next = p;
		ft_stack_last(*stack_a) = NULL;
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
		tmp = p->next;
		ft_stack_last(*stack_b)->next = p;
		p->next = NULL;
		*stack_b = tmp;
	}
}

// rrr : rra and rrb at the same time.

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	ra(stack_b);
}