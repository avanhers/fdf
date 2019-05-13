/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:05:08 by avanhers          #+#    #+#             */
/*   Updated: 2019/04/04 18:33:13 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	size_t	last;
	int		find;

	find = 0;
	str = (char*)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			last = i;
			find = 1;
		}
		i++;
	}
	if ((char)c == '\0')
		return (str + i);
	if (find == 1)
		return (str + last);
	return (NULL);
}
