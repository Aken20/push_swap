/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:52:10 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/10 03:43:18 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	n;
	char	*c_s;

	n = ft_strlen(s);
	c_s = (char *) s;
	if ((unsigned char)c == 0)
		return (c_s + n);
	--n;
	while (s[n] && n > 0)
	{
		if ((unsigned char)s[n] == (unsigned char)c)
		{
			c_s = (char *)s + n;
			return (c_s);
		}
		--n;
	}
	if ((unsigned char)s[n] == (unsigned char)c)
	{
		c_s = (char *)s + n;
		return (c_s);
	}
	return (0);
}
