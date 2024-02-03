/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:04:48 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/02/03 04:07:12 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*p;
	t_stack		*tmp;

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

void	ft_check_if_sorted(t_stack **stack_a, int i)
{
	t_stack	*p;

	if (i < 2)
	{
		ft_free(stack_a, NULL);
		exit(ft_printf(1, "Er9ror\n"));
	}
	p = *stack_a;
	while (p && p->next && ascending(p, 1, 2))
		p = p->next;
	if (!p->next)
	{
		ft_free(stack_a, NULL);
		exit(ft_printf(2, "Error\n"));
	}
	return ;
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

void	ft_set_a(t_stack **stack_a, char **ad)
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
				return (ft_set_a(&stack_a, ad),
					ft_free(&stack_a, NULL), ft_printf(2, "Error\n"));
			ft_set_a(&stack_a, ad);
		}
		ft_check_dup(stack_a);
		ft_check_if_sorted(&stack_a, i);
		ft_sort_stack(&stack_a, &stack_b);
	}
	return (ft_free(&stack_a, &stack_b), 0);
}
