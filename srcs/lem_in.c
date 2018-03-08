/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:41:59 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/07 14:33:11 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	dsp_path(t_path *p)
{
	ft_putstr("Path : ");
	while (p->next)
	{
		ft_printf ("%s <- ", p->name);
		p = p->next;
	}
	ft_putendl(p->name);
}

void	dsp_rooms(t_room *r)
{
	t_link	*tmp;
	while (r)
	{
		write(1, "----------\n", 11);
		ft_printf("Name = %s\n\n", r->name);
		ft_printf("Path value = %d\n", r->count);
		tmp = r->link;
		ft_printf("Connected to : \n");
		while (tmp)
		{
			ft_printf("-%s\n", tmp->adress->name);
			tmp = tmp->next;
		}
		write(1, "----------\n", 11);
		r = r->next;
	}
}

int store_mdr(t_env *e)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
			start_end(e, line);
		else if (check_room(line))
			store_room(e, line);
		else if (check_link(e, line))
		{
			e->line = line;
			return (1);
		}
		else if (line[0] != '#')
		{
			free(line);
			lem_exit(e);
			return (0);
		}
		free(line);
	}
	return (0);
}

void		lem_parse(t_env *e)
{
	store_ant(e);
	store_mdr(e);
	store_link(e);
}

void		lem_in(t_env *e)
{
	t_path	*p;

	lem_parse(e);
	if (lem_path(e))
	{
		p = get_path(e);
		//dsp_path(p);
		view_ants_moves(p, e);	
	}
	//dsp_rooms(e->room);		
}
