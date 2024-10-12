/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:32:26 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/02/08 12:28:10 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static	long long	ft_atoi_check(const char *str)
{
	long long	i;
	long long	c;
	long long	ret;

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
	if (str[i] || c >= 19)
		return (ret);
	return (2);
}

long long	ft_atoi(const char *str)
{
	int			s;
	long long	aoi;
	int			i;

	i = 0;
	s = 1;
	if (str[i] == 0)
		return (0);
	if (ft_atoi_check(str) != 2)
		return (21474836479);
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
	while (str[i] >= 48 && str[i] <= 57 && aoi < 2147483647)
		aoi = (aoi * 10) + (str[i++] - 48);
	if (str[i] || (s == 1 && aoi > 2147483647) || (s == -1 && aoi > 2147483648))
		return (21474836479);
	return (aoi * s);
}
