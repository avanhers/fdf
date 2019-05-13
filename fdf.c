/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:40:15 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/02 17:50:20 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "mlx.h"
#include "fdf_struct.h"
#include "fdf_prototype.h"
#include "fdf_define.h"

t_map			*map_cpy(t_map *mapi)
{
	t_map	*map;
	int		i;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->nb_l = mapi->nb_l;
	map->nb_c = mapi->nb_c;
	map->points = (t_points*)malloc(sizeof(t_points) * map->nb_c * map->nb_l);
	if (!(map->points))
	{
		free(map);
		return (NULL);
	}
	i = -1;
	while (++i < mapi->nb_c * mapi->nb_l)
	{
		(map->points)[i].x = (mapi->points)[i].x;
		(map->points)[i].y = (mapi->points)[i].y;
		(map->points)[i].z = (mapi->points)[i].z;
	}
	return (map);
}

static int		init_mlx(t_env *env, char *name)
{
	if (!(env->mlx_ptr = mlx_init()))
		return (0);
	env->win = mlx_new_window(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, name);
	if (!(env->win))
		return (0);
	(env->img).img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!((env->img).img_ptr))
	{
		mlx_destroy_window(env->mlx_ptr, env->win);
		return (0);
	}
	return (1);
}

static int		init_env(t_env *env, t_map *map, char *name)
{
	if (!(init_mlx(env, name)))
		return (0);
	env->mapi = map_cpy(map);
	if (!(env->mapi))
	{
		free_and_close(env, 0);
		return (0);
	}
	env->img.data = (int*)mlx_get_data_addr(env->img.img_ptr, &(env->img.bpp),
			&(env->img.size_l), &(env->img.endian));
	env->tile_h = 4;
	env->tile_l = 8;
	return (1);
}

int				update_img(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, (env->img).img_ptr);
	(env->img).img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!((env->img).img_ptr))
		return (0);
	env->img.data = (int*)mlx_get_data_addr(env->img.img_ptr, &(env->img.bpp),
			&(env->img.size_l), &(env->img.endian));
	return (1);
}

int				fdf(char *filename)
{
	int		fd;
	t_env	env;
	t_map	*map;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (0);
	if (!(read_map(fd, map)))
	{
		free(map);
		return (0);
	}
	env.map = map;
	close(fd);
	if (!(init_env(&env, map, filename)))
		return (0);
	mlx_string_put(env.mlx_ptr, env.win, 800, 600, 15125, "Press any touch");
	mlx_key_hook(env.win, &deal_key, &env);
	mlx_loop(env.mlx_ptr);
	return (1);
}
