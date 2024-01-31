/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:27:48 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/10 03:45:53 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_counting(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	char	*ft_set(char *s, int n, int len)
{
	int		c;
	long	l;

	l = 10;
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
	}
	len--;
	if (n > 0)
		s[len] = (n % 10) + 48;
	len--;
	while (n >= l)
	{
		l *= 10;
		c = (n % l);
		s[len] = c / (l / 10) + 48;
		len--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_counting(n);
	if (n != 0)
	{
		s = malloc(len + 1);
		if (!s)
			return (0);
		s = ft_set(s, n, len);
		s[len] = 0;
		return (s);
	}
	return (0);
}
