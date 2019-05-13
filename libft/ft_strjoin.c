/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:05:21 by avanhers          #+#    #+#             */
/*   Updated: 2019/04/04 19:59:08 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	else
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_strcpy(res, s1);
		ft_strcat(res, s2);
		return (res);
	}
	return (NULL);
}
