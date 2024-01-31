/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:48:34 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/22 15:10:27 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_set_start(char const *s1, char const *set, size_t n)
{
	size_t	l;
	size_t	s_len;

	l = 0;
	s_len = 0;
	while (set[s_len])
		s_len++;
	if (s1[n] && set[l])
	{
		while (l <= s_len)
		{
			while (s1[n] == set[l] && set[l] != 0)
			{
				n++;
				l = 0;
				while (s1[n] != set[l] && set[l] != 0)
					++l;
			}
			l++;
		}
	}
	return (n);
}

static	size_t	ft_set_end(char const *s1, char const *set, size_t n)
{
	size_t	l;
	size_t	s_len;

	l = 0;
	s_len = 0;
	while (set[s_len])
		s_len++;
	if (s1[n] && set[l])
	{
		while (l <= s_len)
		{
			while (s1[n] == set[l] && set[l] != 0 && n > 0)
			{
				n--;
				l = 0;
				while (s1[n] != set[l] && set[l] != 0)
					++l;
			}
			l++;
		}
	}
	return (n);
}

char	*ft_strtrim(char *s1, char const *set)
{
	char	*s;
	size_t	start;
	size_t	end;
	size_t	n;

	if (!s1)
		return (NULL);
	if (!*s1)
		return (free(s1), NULL);
	n = 0;
	start = ft_set_start(s1, set, n);
	while (s1[n])
		n++;
	end = ft_set_end(s1, set, n - 1);
	if (start >= n || end >= n)
		return (free(s1), NULL);
	s = malloc((end - start + 2));
	if (!s)
		return (free(s1), NULL);
	n = 0;
	while (s1[start] && start <= end)
		s[n++] = s1[start++];
	s[n] = 0;
	return (free(s1), s);
}
