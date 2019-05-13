/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:12:36 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/09 19:28:10 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_struct.h"
#include "fdf_prototype.h"
#include <stdlib.h>
#include "mlx.h"

void	reinitialize(t_env *env)
{
	env->tile_h = 4;
	env->tile_l = 8;
	free((env->map)->points);
	free(env->map);
	if (!(env->map = map_cpy(env->mapi)))
	{
		free(env->mapi->points);
		free(env->mapi);
		mlx_destroy_image(env->mlx_ptr, (env->img).img_ptr);
		mlx_destroy_window(env->mlx_ptr, env->win);
		exit(1);
	}
}

void	zoom_and_effect(int key, t_env *env)
{
	if (key == 69)
	{
		env->tile_h += 2;
		env->tile_l += 4;
	}
	else if (key == 78)
	{
		env->tile_h -= 2;
		env->tile_l -= 4;
	}
	else if (key == 13)
		env->tile_h += 1;
	else if (key == 1)
		env->tile_h -= 1;
	else if (key == 0)
		env->tile_l -= 1;
	else if (key == 2)
		env->tile_l += 1;
}

void	translate(int key, t_env *env)
{
	int i;

	i = -1;
	if (key == 123)
		while (++i < env->map->nb_c * env->map->nb_l)
			(env->map->points)[i].x -= 4;
	else if (key == 124)
		while (++i < env->map->nb_c * env->map->nb_l)
			(env->map->points)[i].x += 4;
	else if (key == 125)
		while (++i < env->map->nb_c * env->map->nb_l)
			(env->map->points)[i].y += 4;
	else if (key == 126)
		while (++i < env->map->nb_c * env->map->nb_l)
			(env->map->points)[i].y -= 4;
}

void	altitude(int key, t_env *env)
{
	int i;

	i = -1;
	if (key == 67)
	{
		while (++i < env->map->nb_c * env->map->nb_l)
			(env->map->points)[i].z *= 2;
	}
	if (key == 75)
	{
		while (++i < env->map->nb_c * env->map->nb_l)
			(env->map->points)[i].z /= 2;
	}
}

int		deal_key(int key, t_env *env)
{
	if (key == 69 || key == 78 || (key >= 0 && key < 3) || key == 13)
		zoom_and_effect(key, env);
	if (key >= 123 && key <= 126)
		translate(key, env);
	if (key == 67 || key == 75)
		altitude(key, env);
	if (!(update_img(env)))
	{
		free(env->mapi->points);
		free(env->mapi);
		free(env->map->points);
		free(env->map);
		exit(1);
	}
	if (key == 15)
		reinitialize(env);
	if (key == 53)
		free_and_close(env, 1);
	if (!(draw_map_iso(env, env->map)))
		free_and_close(env, 1);
	return (0);
}
