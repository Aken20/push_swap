/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:06:20 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/02/06 07:30:28 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_num(t_stack *stack, int target)
{
	while (--target)
		stack = stack->next;
	return (stack->data);
}

int	ascending(t_stack *stack, int target1, int target2)
{
	return (get_num(stack, target1) < get_num(stack, target2));
}

t_stack	*ft_stack_last(t_stack *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a->next != NULL)
		stack_a = stack_a->next;
	return (stack_a);
}

void	ft_add_to_a(t_stack **stack_a, t_stack *new)
{
	t_stack	*p;

	if (!stack_a || !new)
		return ;
	else if (*stack_a == NULL)
		*stack_a = new;
	else
	{
		p = ft_stack_last(*stack_a);
		p->next = new;
	}
}

t_stack	*ft_new_node(int data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}
