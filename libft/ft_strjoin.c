/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 23:02:49 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/22 10:23:23 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	size_t	l1;
	size_t	len;
	char	*sjn;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s2)
		return (ft_strdup((char *)s1));
	if (!s1)
		return (ft_strdup((char *)s2));
	l = ft_strlen(s1);
	l1 = ft_strlen(s2);
	len = (l + l1);
	sjn = (char *) malloc(len + 1);
	if (!sjn)
		return (0);
	l = -1;
	while (s1[++l])
		sjn[l] = s1[l];
	l1 = 0;
	while (s2[l1])
		sjn[l++] = s2[l1++];
	sjn[l] = 0;
	return (sjn);
}
