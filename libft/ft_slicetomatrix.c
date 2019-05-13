/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slicetomatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:36:35 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/02 09:30:31 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_slicetomatrix(t_slice *slice, size_t n_c, size_t nb_l)
{
	int			**mat;
	size_t		i;
	size_t		j;
	char		**line;

	if (!(mat = (int**)malloc(sizeof(int*) * nb_l)))
		return (NULL);
	i = -1;
	while (++i < nb_l)
	{
		if (!(line = ft_strsplit((slice->data)[i], ' ')))
			return (NULL);
		if (!(mat[i] = (int*)malloc(sizeof(int) * n_c)))
			return (NULL);
		j = -1;
		while (++j < n_c)
		{
			mat[i][j] = ft_atoi(line[j]);
			free(line[j]);
		}
	}
	return (mat);
}
