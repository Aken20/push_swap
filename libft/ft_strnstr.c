/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:03:28 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/10 03:43:13 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	const char	*ft2str(const char *s_in, const char *s_for, size_t len)
{
	int		n;
	int		i;
	size_t	l;

	i = 0;
	n = 0;
	while (*(s_in + n + i) && len > 0)
	{
		n = 0;
		l = len;
		while (*(s_in + n + i) == s_for[n] && s_for[n] && l > 0)
		{
			++n;
			--l;
		}
		if (s_for[n] == 0)
			return (s_in + i);
		if (s_in[n] == 0)
			return (0);
		i++;
		len--;
	}
	return (NULL);
}

char	*ft_strnstr(const char *s_in, const char *s_for, size_t len)
{
	char	*p;

	if (*s_for == 0)
		return ((char *) s_in);
	if (!s_in && len == 0)
		return (NULL);
	if (*s_in == 0 && *s_for != 0)
		return (NULL);
	while (*s_in != *s_for && *s_in != 0 && len > 0)
	{
		++s_in;
		--len;
	}
	if (*s_in == *s_for && s_in)
	{
		p = (char *) ft2str(s_in, s_for, len);
		return (p);
	}
	return (NULL);
}
