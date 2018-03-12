/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_store.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:50:20 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/12 18:57:00 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		store_ant(t_env *e)
{
	char *line;
	char *to_del;

	to_del = NULL;
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
		{
			store_map(e, &e->map, line);
			free(line);
		}
		else
			break ;
	}
	if (line == NULL || ft_strcmp(to_del = ft_itoa(ft_atoi(line)), line))
		lem_exit(e, "ERROR\n");
	e->ant = ft_atoi(line);
	store_map(e, &e->map, line);
	free(line);
	if (to_del)
		free(to_del);
	if (e->ant <= 0)
		lem_exit(e, "ERROR\n");
}

void		store_room(t_env *e, char **tab)
{
	t_room	*tmp;
	int		x;

	x = 0;
	while (tab[x])
		++x;
	if (x != 3 || tab[0][0] == 'L' || !ft_str_is_numeric(tab[1])
	|| !ft_str_is_numeric(tab[2]) || ft_strchr(tab[0], '-'))
	{
		ft_strsplitdel(tab);
		lem_exit(e, "ERROR\n");
	}
	if (!e->room)
		e->room = add_room(e, tab[0]);
	else
	{
		tmp = e->room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_room(e, tab[0]);
	}
	ft_strsplitdel(tab);
}

void		add_start_end(t_env *e, char **tab, char *str)
{
	t_room	*tmp;

	if (!(e->room))
	{
		e->room = add_room(e, tab[0]);
		tmp = e->room;
	}
	else
	{
		tmp = e->room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_room(e, tab[0]);
		tmp = tmp->next;
	}
	if (!ft_strcmp(str, "##start"))
		e->start = tmp;
	else
		e->end = tmp;
	ft_strsplitdel(tab);
}

void		store_start_end(t_env *e, char *str)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
		{
			store_map(e, &e->map, line);
			free(line);
		}
		else
			break ;
	}
	add_start_end(e, ft_strsplit(line, ' '), str);
	store_map(e, &e->map, line);
	free(line);
}

void		store_map(t_env *e, t_data **map, char *line)
{
	t_data	*new;
	t_data	*tmp;

	if (!(new = ft_memalloc(sizeof(t_data)))
	|| !(new->name = ft_strdup(line)))
		lem_exit(e, "ERROR\n");
	tmp = *map;
	if (!tmp)
	{
		*map = new;
		return ;
	}
	while (tmp)
	{
		if (!tmp->next)
		{
			tmp->next = new;
			return ;
		}
		tmp = tmp->next;
	}
}
