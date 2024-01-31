/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:31:29 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/10 03:42:05 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_rev_move(char *c_dest, char *c_src, int n)
{
	int	i;

	i = n - 1;
	while (i >= 0 && n >= 0)
	{
		c_dest[i] = c_src[i];
		--i;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, int n)
{
	char	*c_dest;
	char	*c_src;
	int		i;

	i = 0;
	if (!dest && !src)
		return (dest);
	c_dest = (char *) dest;
	c_src = (char *) src;
	if (c_src > c_dest)
	{
		while (i < n)
		{
			c_dest[i] = c_src[i];
			i++;
		}
		return (dest);
	}
	else if (c_src < c_dest)
		ft_rev_move(c_dest, c_src, n);
	return (dest);
}
