/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 03:49:04 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/10 03:42:53 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	char	*c_src;
	char	*c_dest;

	n = 0;
	i = 0;
	c_src = (char *)src;
	n = ft_strlen(c_src);
	if (!dest)
		return (n);
	c_dest = (char *) dest;
	if (dstsize > 0)
	{
		while (i < n && dstsize > 1 && c_src[i])
		{
			c_dest[i] = c_src[i];
			++i;
			--dstsize;
		}
		c_dest[i] = '\0';
	}
	return (n);
}
