/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:45:02 by overetou          #+#    #+#             */
/*   Updated: 2018/03/07 14:24:44 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	create_link(t_room *room, char *name)
{
	t_data	*link;

	if (!(room->link))
	{
		room->link = (t_data*)malloc(sizeof(t_data));
		(room->link)->name = ft_strdup(name);
		(room->link)->next = NULL;
	}
	else
	{
		link = room->link;
		while (link->next)
			link = link->next;
		link->next = (t_data*)malloc(sizeof(t_data));
		link->next->name = ft_strdup(name);
		link->next->next = NULL;
	}
	return (room->link);
}

void    add_link(t_env *e, char *one)
{
	char	**tab;
    char    *two;
    t_room  *tmp;

	tab = ft_strsplit(one, '-');
    one = tab[0];
    two = tab[1];
    tmp = e->room;
    while (tmp && ft_strcmp(tmp->name, one) != 0)
        tmp = tmp->next;
	create_link(tmp, two);
	tmp = e->room;
    while (tmp && ft_strcmp(tmp->name, two) != 0)
        tmp = tmp->next;
	create_link(tmp, one);
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
