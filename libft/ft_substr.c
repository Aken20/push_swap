/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:16:58 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/06 16:02:07 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_m(unsigned int start, size_t len, size_t n)
{
	char	*sub;

	if ((n - start) < len)
		sub = malloc((n - start) + 1);
	else
		sub = malloc(len + 1);
	if (!sub)
		return (0);
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[n])
		n++;
	if (start > n)
	{
		sub = malloc(1);
		if (!sub)
			return (0);
		*sub = 0;
		return (sub);
	}
	sub = ft_m(start, len, n);
	if (!sub)
		return (0);
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = 0;
	return (sub);
}
