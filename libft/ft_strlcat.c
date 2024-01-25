/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:00:07 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/06 16:01:46 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	c;
	size_t	n;
	size_t	k;

	i = 0;
	n = ft_strlen(src);
	if (dest == 0 && size == 0)
		return (n);
	c = ft_strlen(dest);
	if (size < c)
		return (n + size);
	k = c;
	while (i + 1 < size - k && src[i])
	{
		*(dest + c) = *(src + i);
		i++;
		c++;
	}
	dest[c] = (0);
	if (size >= k)
		return (k + n);
	else
		return (size + n);
}
