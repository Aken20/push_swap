/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:23:43 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/10 03:41:51 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int				i;
	int				c;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	i = 0;
	c = n;
	c_s1 = (unsigned char *) s1;
	c_s2 = (unsigned char *) s2;
	while (i < c)
	{
		if (c_s1[i] == c_s2[i])
			++i;
		else
			return (c_s1[i] - c_s2[i]);
	}
	return (0);
}
