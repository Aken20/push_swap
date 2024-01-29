/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:32:26 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/29 15:59:07 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_check(const char *str)
{
	int	i;
	int	c;
	int	ret;

	ret = -1;
	c = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ret = 0;
		i++;
	}
	while (str[i] == 48)
		i++;
	while (str[i] >= 48 && str[i++] <= 57)
		c++;
	if (c >= 19)
		return (ret);
	return (2);
}

int	ft_s_atoi(const char *str)
{
	int			s;
	int			aoi;
	int			i;

	i = 0;
	s = 1;
	if (str[i] == 0)
		return (0);
	if (ft_check(str) != 2)
		return (ft_check(str));
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		++i;
	}
	if (str[i] >= 48 && str[i] <= 57)
		aoi = (str[i++] - 48);
	else
		exit (ft_printf(2, "INVALID INPUT\n"));
	while (str[i] >= 48 && str[i] <= 57)
		aoi = (aoi * 10) + (str[i++] - 48);
	return (aoi * s);
}
