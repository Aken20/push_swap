/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 04:47:17 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/08/19 05:32:08 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || !f || (!s && !f))
		return ;
	str = (char *)s;
	while (str[i] != 0)
	{
		(*f)(i, str + i);
		i++;
	}
}
