/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:55:49 by avanhers          #+#    #+#             */
/*   Updated: 2019/04/04 18:30:05 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*res;
	const char	*source;

	res = dst;
	source = src;
	i = 0;
	while (i < n)
	{
		res[i] = source[i];
		i++;
	}
	return (dst);
}
