/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:04:48 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/31 13:08:24 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*p;
	t_stack		*tmp;

	p = NULL;
	if (stack_a && *stack_a)
	{
		p = *stack_a;
		while (p)
		{
			tmp = p->next;
			free (p);
			p = tmp;
		}
		*stack_a = NULL;
	}
	if (stack_b && *stack_b)
	{
		p = *stack_b;
		while (p)
		{
			tmp = p->next;
			free (p);
			p = tmp;
		}
		*stack_b = NULL;
	}
}

int	ft_check_dup(t_stack *stack_a)
{
	t_stack	*check;
	t_stack	*check2;

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
				{
					ft_free(&stack_a, NULL);
					exit(ft_printf(1, "Error\n"));
				}
			}
			check = check->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int	ft_set_a(t_stack **stack_a, char **ad)
{
	int	i;

	i = 0;
	while (ad && ad[i])
	{
		if (ft_s_atoi(ad[i]) != 21474836479)
			ft_add_to_a(stack_a, ft_new_node(ft_s_atoi(ad[i])));
		else if (ft_s_atoi(ad[i]) == 21474836479)
		{
			i = 0;
			while (ad[i])
				free(ad[i++]);
			free(ad);
			ft_free(stack_a, NULL);
			exit(ft_printf(2, "Error\n"));
		}
		i++;
	}
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
	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		if (!av[1][0])
			exit(ft_printf(2, "Error\n"));
		while (av[i])
		{
			ad = ft_split(av[i++], ' ');
			if (!ad || !ad[0])
			{
				ft_set_a(&stack_a, ad);
				ft_free(&stack_a, NULL);
				exit(ft_printf(2, "Error\n"));
			}
			ft_set_a(&stack_a, ad);
		}
		if (i <= 2)
		{
			ft_free(&stack_a, NULL);
			exit(ft_printf(2, "Error\n"));
		}
		ft_check_dup(stack_a);
		// stack_a = sort_stack(stack_a);
		// sa(&stack_a);
		// sb(&stack_b);
		// ss(&stack_a, &stack_b);
		// ra(&stack_a);
		// rb(&stack_b);
		// rr(&stack_a, &stack_b);
		// rra(&stack_a);
		// rrb(&stack_b);
		// rrr(&stack_a, &stack_b);
		// pa(&stack_a, &stack_b);
		// pb(&stack_a, &stack_b);
		// while (stack_a)
		// {
		// 	ft_printf(1, "stack_a   %d\n", stack_a->data);
		// 	stack_b = stack_a;
		// 	stack_a = stack_a->next;
		// 	free(stack_b);
		// }
	}
	ft_free(&stack_a, &stack_b);
	return (0);
}
