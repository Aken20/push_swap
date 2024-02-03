/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:02:40 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/02/02 20:57:03 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct stack
{
	int				data;
	struct stack	*next;
}					t_stack;

t_stack		*ft_stack_last(t_stack *stack_a);
t_stack		*sort_stack(t_stack *stack_a);
t_stack		*ft_new_node(int data);
long long	ft_s_atoi(const char *str);
int			ascending(t_stack *stack, int target1, int target2);
int			get_num(t_stack *stack, int target);
void		ft_add_to_a(t_stack **stack_a, t_stack *new);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ft_free(t_stack **stack_a, t_stack **stack_b);
void		ft_check_if_sorted(t_stack **stack_a, int i);
void		ft_sort_three(t_stack **stack_a);
void		ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_stack(t_stack **stack_a, t_stack **stack_b);

#endif