/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prototype.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:32:30 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/02 17:48:13 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PROTOTYPE_H
# define FDF_PROTOTYPE_H

# include "fdf_struct.h"

int		fdf(char *filename);
int		read_map(int fd, t_map *map);

void	put_line(t_points a, t_points b, t_env *env);

int		update_img(t_env *env);

int		draw_map_iso(t_env *env, t_map *map);
t_map	*map_cpy(t_map *map);
int		deal_key(int key, t_env *env);

void	free_slice(t_slice *slice, int size);
void	free_and_close(t_env *env, int all);
#endif
