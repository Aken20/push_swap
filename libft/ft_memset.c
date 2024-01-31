/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:58:42 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/10 03:42:10 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, unsigned int len)
{
	int		i;
	char	*c_b;
	int		l;

	i = 0;
	l = len;
	c_b = (char *) b;
	while (i < l)
	{
		c_b[i] = c;
		++i;
	}
	return (b);
}
