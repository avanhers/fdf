/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:31:22 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/02 17:50:53 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_prototype.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
		fdf(argv[1]);
	return (0);
}
