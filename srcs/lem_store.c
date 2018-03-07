/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_store.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:50:20 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/07 15:41:37 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	store_room(t_env *e, char *line)
{
	char	**tab;
	t_room	*tmp;

	tab = ft_strsplit(line, ' ');
	if (!e->room)
		e->room = add_room(tab[0]);
	else
	{
		tmp = e->room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_room(tab[0]);
	}
	ft_strsplitdel(tab);
}

void		start_end(t_env *e, char *line)
{
	char	**tab;
	char	*l;
	t_room	*tmp;

	get_next_line(0, &l);
	tab = ft_strsplit(l, ' ');
	if (!(e->room))
	{
		e->room = add_room(tab[0]);
		tmp = e->room;
	}
	else
	{
		tmp = e->room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_room(tab[0]);
		tmp = tmp->next;
	}
	if (ft_strcmp(line + 2, "start") == 0)
		e->start = tmp;
	else
		e->end = tmp;
	free(l);
	ft_strsplitdel(tab);
}

void		store_ant(t_env *e)
{
	char *line;

	while (1)
	{
		if (get_next_line(0, &line) < 1)
			lem_exit(e);
		if (line[0] == '#')
			store_cmt(e, line);
		else
		{
			e->ant = ft_atoi(line);
			free(line);
			break ;
		}
		free(line);
	}
	if (!e->ant || e->ant < 0 || e->ant > 2147483647)
		lem_exit(e);
}
