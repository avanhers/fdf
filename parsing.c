/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 10:24:29 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/03 12:14:04 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_struct.h"
#include "fdf_prototype.h"
#include <stdio.h>

static int	nb_number(char *s)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' ')
			i++;
		if (s[i])
			res++;
		while (s[i] != ' ' && s[i] != '\0')
			i++;
	}
	return (res);
}

static int	read_to_slice(int fd, t_slice *slice)
{
	int		code;
	char	*line;
	int		nb_l;
	int		i;

	code = 1;
	nb_l = 0;
	i = 0;
	while ((code = get_next_line(fd, &line)))
	{
		if (code == -1 || !(ft_sliceappend(slice, line)) || line[0] < 32)
		{
			free_slice(slice, i);
			return (0);
		}
		i++;
		nb_l++;
	}
	if (code == 0)
		free(line);
	return (nb_l);
}

static int	slice_tomap(t_slice *slice, t_map *map)
{
	char	**number;
	int		i;
	int		j;
	int		num;

	num = 0;
	map->points = (t_points*)malloc(sizeof(t_points) * map->nb_c * map->nb_l);
	if (!(map->points) || !(i = -1))
		return (0);
	while (++i < map->nb_l && (j = -1))
	{
		number = ft_strsplit(slice->data[i], ' ');
		while (++j < map->nb_c)
		{
			(map->points)[num].x = j;
			(map->points)[num].y = i;
			(map->points)[num].z = ft_atoi(number[j]);
			num++;
			free(number[j]);
		}
		free(slice->data[i]);
		free(number);
	}
	free(slice->data);
	return (1);
}

static int	verif_slice(int nb_l, int nb_col, t_slice *slice)
{
	int		i;

	i = 0;
	while (i < nb_l)
	{
		if (nb_number(slice->data[i]) != nb_col)
			return (0);
		i++;
	}
	return (1);
}

int			read_map(int fd, t_map *map)
{
	t_slice	*slice;

	if (!(slice = ft_slicenew()))
		return (0);
	if (!(map->nb_l = read_to_slice(fd, slice)))
		return (0);
	map->nb_c = nb_number(slice->data[0]);
	if (!verif_slice(map->nb_l, map->nb_c, slice))
	{
		free_slice(slice, map->nb_l);
		return (0);
	}
	if (!slice_tomap(slice, map))
	{
		free_slice(slice, map->nb_l);
		return (0);
	}
	free(slice);
	return (1);
}
