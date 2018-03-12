/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_pass.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:12:30 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/12 19:18:10 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int			lem_path(t_env *e)
{
	t_link	*queue;
	t_link	*tmp;
	t_link	*last;

	e->start->count = 1;
	if (!(queue = (t_link*)malloc(sizeof(t_link))))
		lem_exit(e, "ERROR\n");
	queue->adress = e->start;
	queue->next = NULL;
	tmp = queue;
	last = queue;
	while (tmp)
	{
		if (process_connections(tmp->adress, &last, e))
		{
			del_link(queue);
			return (1);
		}
		tmp = tmp->next;
	}
	del_link(queue);
	return (0);
}

void		mv_ants(t_path *p, t_env *e)
{
	t_path	*next;

	next = p->next;
	while (next->next)
	{
		if (next->ant)
		{
			p->an = next->an;
			p->ant += 1;
			next->ant = 0;
		}
		p = next;
		next = next->next;
	}
	if (next->ant)
	{
		(next->ant)--;
		p->an = e->ant - next->ant;
		p->ant += 1;
	}
}

void		view_ants_moves(t_path *p, t_env *e)
{
	t_path *origin;

	origin = p;
	while (p->ant != e->ant)
	{
		mv_ants(p, e);
		print_ants(p, e);
	}
	del_path(origin);
}
