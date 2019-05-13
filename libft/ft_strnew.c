/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:20:48 by avanhers          #+#    #+#             */
/*   Updated: 2019/04/04 19:57:29 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res = ft_memset(res, '\0', size + 1);
	return (res);
}
