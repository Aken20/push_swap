/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:54:30 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/10 03:41:45 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*c_s;
	int		i;

	i = 0;
	c_s = (char *) s;
	while (n > 0)
	{
		if ((unsigned char)c_s[i] == (unsigned char)c)
			return (c_s + i);
		--n;
		c_s++;
	}
	return (NULL);
}
