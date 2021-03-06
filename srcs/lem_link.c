/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:45:02 by overetou          #+#    #+#             */
/*   Updated: 2018/03/12 23:37:00 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int			check_link(t_env *e, char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
		x++;
	if (x != 2 || !find_room(tab[0], e) || !find_room(tab[1], e))
		return (0);
	return (1);
}

void		create_link(t_env *e, t_room *room, t_room *adress)
{
	t_link	*link;

	if (!(room->link))
	{
		if (!(room->link = (t_link*)malloc(sizeof(t_link))))
			lem_exit(e, NULL);
		(room->link)->adress = adress;
		(room->link)->next = NULL;
	}
	else
	{
		link = room->link;
		while (link->next)
			link = link->next;
		if (!(link->next = (t_link*)malloc(sizeof(t_link))))
			lem_exit(e, NULL);
		link->next->adress = adress;
		link->next->next = NULL;
	}
}

void		add_link(t_env *e, char **tab)
{
	t_room	*tmp;

	tmp = find_room(tab[0], e);
	create_link(e, tmp, find_room(tab[1], e));
	tmp = find_room(tab[1], e);
	create_link(e, tmp, find_room(tab[0], e));
}

void		store_link(t_env *e, char *line)
{
	char **tab;

	tab = ft_strsplit(line, '-');
	free(line);
	while (tab)
	{
		if (check_link(e, tab))
			add_link(e, tab);
		else if (line[0] == '#')
			store_map(e, &e->cmt, line);
		else
		{
			ft_strsplitdel(tab);
			break ;
		}
		ft_strsplitdel(tab);
		tab = NULL;
		if (get_next_line(0, &line) > 0)
		{
			store_map(e, &e->map, line);
			tab = ft_strsplit(line, '-');
			free(line);
		}
	}
}
