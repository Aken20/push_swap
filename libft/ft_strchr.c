/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:35:35 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/10 03:42:33 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*c_s;

	while (*s)
	{
		if (*s != (char)c)
			++s;
		else
		{
			c_s = (char *) s;
			return (c_s);
		}
	}
	if (*s == (char)c)
	{
		c_s = (char *) s;
		return (c_s);
	}
	return (NULL);
}
