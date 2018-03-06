/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_store.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:50:20 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/06 16:50:27 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	add_link(t_room *room, char *name)
{
	t_data	*link;

	link = e->room->link;
	if (!link)
	{
		link = (t_data*)malloc(sizeof(t_data));
		link->name = name;
		link->next = NULL;
	}
	else
	{
		while (link->next)
			link = link->next;
		link->next = (t_data*)malloc(sizeof(t_data));
		link->next->name = name;
		link->next->next = NULL;
	}
}

void	store_link(t_env *e, char *line)
{
	char	**tab;
	char	*tmp;

	tab = ft_strsplit(line, '-');
	tmp = tab[0];
	ft_strsplitdel(tab);
	while (e->room)
	{
		if (ft_strcmp(e->room->name, tmp) == 0)
		{
			add_link(e->room, tmp);
			//e->room->link->name = tmp;
		}
		e->room = e->room->next;
	}
}

void	store_room(t_env *e, char *line)
{
	char	**tab;
	t_room	*tmp;

	tab = ft_strsplit(line, ' ');
	tmp = e->room;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add_room(tab[0]);
	ft_strsplitdel(tab);
}

void		store_cmt(t_env *e, char *line)
{
	t_data *tmp;

	tmp = NULL;
	tmp->next = e->cmt;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_data*)malloc(sizeof(t_data));
	tmp->name = ft_strdup(line);
	tmp->next = NULL;
}

void		start_end(t_env *e, char *line)
{
	char	**tab;
	char	*l;
	t_room	*tmp;

	get_next_line(0, &l);	
	tab = ft_strsplit(l, ' ');
	tmp = e->room;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add_room(tab[0]);
	if (ft_strcmp(line + 2, "start") == 0)
		e->start = tmp->next;
	else
		e->end = tmp->next;
	free(l);
	ft_strsplitdel(tab);
}

void		store_ant(t_env *e)
{
	char *line;

	get_next_line(0, &line);
	e->ant = ft_atoi(line);
	free(line);
}
