/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:14:40 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/02 17:06:32 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_struct.h"
#include "fdf_define.h"

void	brese_oct1(t_points a, t_points b, t_env *env)
{
	int	dx;
	int	dy;
	int eps;

	dx = b.x - a.x;
	dy = b.y - a.y;
	eps = 0;
	while (a.x <= b.x)
	{
		if (2 * eps + 2 * dy < dx)
			eps = eps + dy;
		else
		{
			a.y = a.y + 1;
			eps = eps + dy - dx;
		}
		if (a.x <= 0 || a.x >= WIN_WIDTH || b.x <= 0 || b.x >= WIN_WIDTH
			|| a.y <= 0 || b.y <= 0 || a.y >= WIN_HEIGHT || b.y >= WIN_HEIGHT)
			return ;
		env->img.data[a.y * WIN_WIDTH + a.x] = 15455;
		(a.x)++;
	}
}

void	brese_oct2(t_points a, t_points b, t_env *env)
{
	int	dx;
	int	dy;
	int eps;

	dx = b.x - a.x;
	dy = b.y - a.y;
	eps = 0;
	while (a.y <= b.y)
	{
		if (2 * eps + 2 * dx < dy)
			eps = eps + dx;
		else
		{
			a.x = a.x + 1;
			eps = eps + dx - dy;
		}
		if (a.x <= 0 || a.x >= WIN_WIDTH || b.x <= 0 || b.x >= WIN_WIDTH
			|| a.y <= 0 || b.y <= 0 || a.y >= WIN_HEIGHT || b.y >= WIN_HEIGHT)
			return ;
		env->img.data[a.y * WIN_WIDTH + a.x] = 15455;
		(a.y)++;
	}
}

void	brese_oct8(t_points a, t_points b, t_env *env)
{
	int	dx;
	int	dy;
	int eps;

	dx = b.x - a.x;
	dy = b.y - a.y;
	eps = 0;
	while (a.y >= b.y)
	{
		if (2 * eps + 2 * dx < -dy)
			eps = eps + dx;
		else
		{
			a.x = a.x + 1;
			eps = eps + dy + dx;
		}
		if (a.x <= 0 || a.x >= WIN_WIDTH || b.x <= 0 || b.x >= WIN_WIDTH
			|| a.y <= 0 || b.y <= 0 || a.y >= WIN_HEIGHT || b.y >= WIN_HEIGHT)
			return ;
		env->img.data[a.y * WIN_WIDTH + a.x] = 15455;
		(a.y)--;
	}
}

void	brese_oct4(t_points a, t_points b, t_env *env)
{
	int	dx;
	int	dy;
	int eps;

	dx = b.x - a.x;
	dy = b.y - a.y;
	eps = 0;
	while (a.x >= b.x)
	{
		if (2 * eps + 2 * dy < -dx)
			eps = eps + dy;
		else
		{
			a.y = a.y + 1;
			eps = eps + dy + dx;
		}
		if (a.x <= 0 || a.x >= WIN_WIDTH || b.x <= 0 || b.x >= WIN_WIDTH
			|| a.y <= 0 || b.y <= 0 || a.y >= WIN_HEIGHT || b.y >= WIN_HEIGHT)
			return ;
		env->img.data[a.y * WIN_WIDTH + a.x] = 15455;
		(a.x)--;
	}
}

void	put_line(t_points a, t_points b, t_env *env)
{
	int dx;
	int dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (dx > 0 && dy >= 0 && dx >= dy)
		brese_oct1(a, b, env);
	else if (dx < 0 && dy < 0 && dx <= dy)
		brese_oct1(b, a, env);
	else if (dx >= 0 && dy > 0 && dx <= dy)
		brese_oct2(a, b, env);
	else if (dx <= 0 && dy <= 0 && dx >= dy)
		brese_oct2(b, a, env);
	else if (dx < 0 && dy >= 0 && -dx >= dy)
		brese_oct4(a, b, env);
	else if (dx >= 0 && dy <= 0 && -dx <= dy)
		brese_oct4(b, a, env);
	else if (dx >= 0 && dy <= 0 && dx <= -dy)
		brese_oct8(a, b, env);
	else if (dx <= 0 && dy >= 0 && dx >= -dy)
		brese_oct8(b, a, env);
}
