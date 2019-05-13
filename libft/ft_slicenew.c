/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slice_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:12:59 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/02 09:47:39 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slice		*ft_slicenew(void)
{
	t_slice	*slice;

	if (!(slice = (t_slice*)malloc(sizeof(t_slice))))
		return (NULL);
	if (!(slice->data = (char**)malloc(sizeof(char) * 2)))
		return (NULL);
	slice->len = 0;
	slice->cap = 2;
	return (slice);
}
