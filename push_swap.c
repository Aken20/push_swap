/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:04:48 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/31 06:31:26 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ascending(int a, int b)
{
	return (a <= b);
}

int	ft_check_dup(t_stack *stack_a)
{
	t_stack	*check;
	t_stack	*check2;

	if (!stack_a->next)
		exit(ft_printf(1, "Error\n"));
	while (stack_a)
	{
		check = stack_a;
		while (check)
		{
			check2 = check;
			while (check2->next)
			{
				check2 = check2->next;
				if (check2->data == check->data)
					exit(ft_printf(1, "Error\n"));
			}
			check = check->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

t_stack	*sort_stack(t_stack *stack_a)
{
	int		swap;
	t_stack	*tmp;

	tmp = stack_a;
	while (stack_a->next != NULL)
	{
		if (!ascending(stack_a->data, stack_a->next->data))
		{
			swap = stack_a->data;
			stack_a->data = stack_a->next->data;
			stack_a->next->data = swap;
			stack_a = tmp;
		}
		else
			stack_a = stack_a->next;
	}
	stack_a = tmp;
	return (stack_a);
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
	if (*stack_a == NULL)
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

int	ft_set_a(t_stack **stack_a, char **ad)
{
	int	i;

	i = 0;
	while (ad[i])
		ft_add_to_a(stack_a, ft_new_node(ft_s_atoi(ad[i++])));
	i = 0;
	while (ad[i])
		free(ad[i++]);
	free(ad);
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	char	**ad;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	if (ac > 1)
	{
		if (!av[1][0])
			exit(ft_printf(2, "Error\n"));
		while (av[i])
		{
			ad = ft_split(av[i++], ' ');
			if (!ad || !ad[0])
				exit(ft_printf(2, "Error\n"));
			ft_set_a(&stack_a, ad);
		}
		ft_check_dup(stack_a);
		stack_a = sort_stack(stack_a);
		stack_b = ft_new_node(0);
		pa(&stack_a, &stack_b);
		while (stack_a)
		{
			ft_printf(1, "stack_a			%d\n", stack_a->data);
			stack_a = stack_a->next;
		}
		while (stack_b)
		{
			ft_printf(1, "stack_b			%d\n", stack_b->data);
			stack_b = stack_b->next;
		}
	}
	return (0);
}
