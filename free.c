/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:59:41 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/03 12:10:52 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf_struct.h"
#include "mlx.h"

void	free_slice(t_slice *slice, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(slice->data[i]);
		i++;
	}
	free(slice->data);
	free(slice);
}

void	free_and_close(t_env *env, int all)
{
	if (all == 1)
	{
		free(env->mapi->points);
		free(env->mapi);
		mlx_destroy_image(env->mlx_ptr, (env->img).img_ptr);
		mlx_destroy_window(env->mlx_ptr, env->win);
	}
	free(env->map->points);
	free(env->map);
	exit(0);
}
