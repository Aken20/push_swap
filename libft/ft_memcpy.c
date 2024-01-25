/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:27:50 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/10 03:41:57 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const char *src, int n)
{
	char	*c_dest;
	char	*c_src;
	int		i;

	i = 0;
	c_dest = (char *) dest;
	c_src = (char *) src;
	if (dest || src)
	{
		while (i < n)
		{
			c_dest[i] = c_src[i];
			++i;
		}
	}
	return (dest);
}
