/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:35:36 by avanhers          #+#    #+#             */
/*   Updated: 2019/04/04 20:02:03 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*todel;
	t_list	*lst;

	if (*alst)
	{
		lst = *alst;
		while (lst)
		{
			todel = lst;
			lst = todel->next;
			del(todel->content, todel->content_size);
			free(todel);
		}
		*alst = NULL;
	}
}
