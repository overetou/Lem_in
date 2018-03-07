/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:45:02 by overetou          #+#    #+#             */
/*   Updated: 2018/03/07 16:11:34 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	create_link(t_room *room, t_room *adress)
{
	t_link	*link;

	if (!(room->link))
	{
		room->link = (t_link*)malloc(sizeof(t_link));
		(room->link)->adress = adress;
		(room->link)->next = NULL;
	}
	else
	{
		link = room->link;
		while (link->next)
			link = link->next;
		link->next = (t_link*)malloc(sizeof(t_link));
		link->next->adress = adress;
		link->next->next = NULL;
	}
}

void    add_link(t_env *e, char *line)
{
	char	**tab;
    t_room  *tmp;

	tab = ft_strsplit(line, '-');
    tmp = find_room(tab[0], e);
	create_link(tmp, find_room(tab[1], e));
	tmp = find_room(tab[1], e);
	create_link(tmp, find_room(tab[0], e));
	ft_strsplitdel(tab);
}

int		store_link(t_env *e)
{
	char	*line;

	add_link(e, e->line);
	while (get_next_line(0, &line))
	{
		if (check_link(e, line))
			add_link(e, line);
		else if (line[0] != '#')
			return (0);
        free(line);
	}
	return (1);
}
