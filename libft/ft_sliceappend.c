/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slice_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:48:28 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/02 09:48:07 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	ft_sliceappend(t_slice *slice, char *s)
{
	char	**new_data;
	size_t	i;

	if (!slice || !s)
		return (0);
	if (slice->len == slice->cap)
	{
		slice->cap *= 2;
		if (!(new_data = (char**)malloc(sizeof(char*) * slice->cap)))
			return (0);
		i = -1;
		while (++i < slice->len)
			new_data[i] = (slice->data)[i];
		new_data[i] = s;
		(slice->len)++;
		free(slice->data);
		slice->data = new_data;
	}
	else
	{
		i = slice->len;
		(slice->data)[i] = s;
		slice->len++;
	}
	return (1);
}
