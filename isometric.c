/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:04:40 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/02 17:08:38 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_struct.h"
#include "fdf_prototype.h"
#include "fdf_define.h"
#include "mlx.h"

t_map	*map_to_screen(t_env *env, t_map *map)
{
	t_map	*iso;
	int		i;

	if (!(iso = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	iso->nb_c = map->nb_c;
	iso->nb_l = map->nb_l;
	iso->points = (t_points*)malloc(sizeof(t_points) * map->nb_c * map->nb_l);
	if (!iso->points)
	{
		free(iso);
		return (NULL);
	}
	i = -1;
	while (++i < iso->nb_c * iso->nb_l)
	{
		(iso->points)[i].x = ((map->points)[i].x - (map->points)[i].y)
			* env->tile_l / 2 + WIN_WIDTH / 3;
		(iso->points)[i].y = ((map->points)[i].x + (map->points)[i].y)
			* env->tile_h / 2 + WIN_HEIGHT / 3 - (map->points)[i].z;
		(iso->points)[i].z = (map->points[i]).z;
	}
	return (iso);
}

void	draw_hor(t_env *env, t_map *map, int i)
{
	int	j;

	j = 0;
	while (j < map->nb_c - 1)
	{
		put_line(map->points[i * map->nb_c + j],
			map->points[i * map->nb_c + j + 1], env);
		j++;
	}
}

void	draw_v(t_env *env, t_map *map, int j)
{
	int	i;

	i = 0;
	while (i < map->nb_l - 1)
	{
		put_line(map->points[i * map->nb_c + j],
			map->points[(i + 1) * map->nb_c + j], env);
		i++;
	}
}

void	param(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win, 25, 25, 1677216, "R : ReInitialize");
	mlx_string_put(env->mlx_ptr, env->win, 25, 45, 1677216, "+ - : Zoom");
	mlx_string_put(env->mlx_ptr, env->win, 25, 65, 1677216, "Arrow : Move");
	mlx_string_put(env->mlx_ptr, env->win, 25, 85, 1677216, "W,A,S,D : Effect");
	mlx_string_put(env->mlx_ptr, env->win, 25, 105, 1677216, "/ * : Altitude");
	mlx_string_put(env->mlx_ptr, env->win, 25, 125, 1677216, "ESC : Quit");
}

int		draw_map_iso(t_env *env, t_map *map)
{
	int		i;
	t_map	*iso;

	if (!(iso = map_to_screen(env, map)))
	{
		free_and_close(env, 1);
		return (0);
	}
	i = -1;
	while (++i < iso->nb_l)
		draw_hor(env, iso, i);
	i = -1;
	while (++i < map->nb_c)
		draw_v(env, iso, i);
	free(iso->points);
	free(iso);
	mlx_put_image_to_window(env->mlx_ptr, env->win, env->img.img_ptr, 0, 0);
	param(env);
	return (1);
}
