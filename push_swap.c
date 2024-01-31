/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:04:48 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/31 08:07:47 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	stack_b = NULL;
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
	}
	return (0);
}
