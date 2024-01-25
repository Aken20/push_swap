/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:15:12 by aken              #+#    #+#             */
/*   Updated: 2023/09/03 08:59:37 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*my_cal;
	int			count;

	if (nmemb * size > 2147483647)
		return (0);
	count = nmemb * size;
	if (count < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (0);
	my_cal = (void *) malloc(count);
	if (!my_cal)
		return (0);
	ft_bzero(my_cal, count);
	return (my_cal);
}

/* int	main (void)
{
	int		*min_i;
	char	*org_c;
	int		*org_i;
	char	*min_c;

	min_i = (int *) ft_calloc(4, 10);
	min_c = (char *) ft_calloc(4, 10);
	org_i = (int *) ft_calloc(4, 10);
	org_c = (char *) ft_calloc(4, 10);
} */