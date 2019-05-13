/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:13:38 by avanhers          #+#    #+#             */
/*   Updated: 2019/04/18 10:31:23 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static t_list	*find_elem(int fd, t_list **elem)
{
	t_list	*tmp;

	tmp = *elem;
	if (tmp)
	{
		while (tmp)
		{
			if ((int)tmp->content_size == fd)
				return (tmp);
			tmp = tmp->next;
		}
	}
	if (!(tmp = ft_lstnew("\0", 1)))
		return (NULL);
	tmp->content_size = fd;
	ft_lstadd(elem, tmp);
	return (*elem);
}

static char		*ft_joinfree(int ret, char *buf, t_list **elem)
{
	char	*l;

	l = (*elem)->content;
	buf[ret] = '\0';
	(*elem)->content = ft_strjoin((char*)((*elem)->content), buf);
	free(l);
	if ((*elem)->content == NULL)
		return (NULL);
	else
		return ((*elem)->content);
}

static int		read_join(int fd, t_list **elem, t_list **begin)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	*begin = *elem;
	*elem = find_elem(fd, begin);
	if (*elem == NULL)
		return (-1);
	while (!ft_strchr((*elem)->content, '\n')
		&& ((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		if (ft_joinfree(ret, buf, elem) == NULL)
			return (-1);
	}
	return (1);
}

static int		move_after_line(t_list **elem, int i)
{
	char	*l;
	int		len;

	l = (*elem)->content;
	len = ft_strlen((*elem)->content) - i;
	(*elem)->content = ft_strsub(((char*)((*elem)->content)), i, len);
	free(l);
	if ((*elem)->content == NULL)
		return (-1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*elem = NULL;
	int				i;
	t_list			*begin;

	if (fd < 0 || line == NULL || (read(fd, *line, 0) < 0))
		return (-1);
	if (read_join(fd, &elem, &begin) == -1)
		return (-1);
	i = 0;
	while (((char*)elem->content)[i] != '\n' && ((char*)elem->content)[i])
		i++;
	*line = ft_strsub((char*)elem->content, 0, i);
	if (*line == NULL)
		return (-1);
	if (((char*)elem->content)[i] == '\n')
		i++;
	if (move_after_line(&elem, i) == -1)
		return (-1);
	if (i == 0)
		ft_lst_remove_if(&begin, fd);
	elem = begin;
	return (i ? 1 : 0);
}
