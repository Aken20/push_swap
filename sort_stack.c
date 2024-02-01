/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:10:54 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/02/01 22:42:16 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

void	ft_check_if_sorted(t_stack **stack_a)
{
	t_stack	*p;

	p = *stack_a;
	while (p && p->next && ascending(p->data, p->next->data))
		p = p->next;
	if (!p->next)
	{
		ft_free(stack_a, NULL);
		exit(ft_printf(2, "Error\n"));
	}
	return ;
}

void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*p;

	p = *stack_a;
	if (p && p->next && !ascending(p->data, p->next->data))
	{
		sa(stack_a);
		p = *stack_a;
		if (p && p->next && !ascending(p->data, p->next->data))
			rra(stack_a);
	}
	else
	{
		rra(stack_a);
		p = *stack_a;
		if (p && p->next && !ascending(p->data, p->next->data))
			sa(stack_a);
	}
	return ;
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;
	int		i;

	p = *stack_a;
	i = p->data;
	while (p)
	{
		if (i > p->data)
			i = p->data;
		p = p->next;
	}
	p = *stack_a;
	while (p->data != i)
	{
		ra(stack_a);
		p = *stack_a;
	}
	pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	pa(stack_a, stack_b);
	return ;
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;
	int		i;

	p = *stack_a;
	i = p->data;
	while (p)
	{
		if (i > p->data)
			i = p->data;
		p = p->next;
	}
	p = *stack_a;
	while (p->data != i)
	{
		ra(stack_a);
		p = *stack_a;
	}
	pb(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
	return ;
}

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) == 3)
		ft_sort_three(stack_a);
	else if (ft_stack_size(*stack_a) == 4)
		ft_sort_four(stack_a, stack_b);
	else if (ft_stack_size(*stack_a) == 5)
		ft_sort_five(stack_a, stack_b);
	return ;
}
