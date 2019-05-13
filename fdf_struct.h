/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:05:12 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/03 11:08:34 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# include "libft/libft.h"

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef	struct	s_points
{
	int		x;
	int		y;
	int		z;
}				t_points;

typedef struct	s_map
{
	int			nb_l;
	int			nb_c;
	t_points	*points;
}				t_map;

typedef struct	s_env
{
	void	*mlx_ptr;
	void	*win;
	t_img	img;
	int		tile_l;
	int		tile_h;
	int		padx;
	int		pady;
	t_map	*map;
	t_map	*mapi;
	char	proj;
}				t_env;

#endif
