/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilles_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 04:15:14 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/02/03 04:15:47 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ascending(t_stack *stack, int target1, int target2)
{
	return (get_num(stack, target1) < get_num(stack, target2));
}
