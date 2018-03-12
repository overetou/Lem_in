/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:12:20 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/12 19:19:57 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	add_queue_link(t_env *e, t_room *r, t_link **last)
{
	if (!((*last)->next = (t_link*)malloc(sizeof(t_link))))
		lem_exit(e, "ERROR\n");
	(*last) = (*last)->next;
	(*last)->adress = r;
	(*last)->next = NULL;
}

int		process_connections(t_room *r, t_link **last, t_env *e)
{
	t_link	*tmp;

	tmp = r->link;
	while (tmp)
	{
		if (tmp->adress->count == 0)
		{
			tmp->adress->count = r->count + 1;
			if (tmp->adress == e->end)
				return (1);
			add_queue_link(e, tmp->adress, last);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_room	*find_next_room(t_link *l, int count)
{
	while (l->adress->count != count)
		l = l->next;
	return (l->adress);
}

t_path	*create_p_node(t_env *e, char *name, int n)
{
	t_path	*new;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		lem_exit(e, "ERROR\n");
	if (!(new->n = ft_strdup(name)))
		lem_exit(e, "ERROR\n");
	new->ant = n;
	return (new);
}

t_path	*get_path(t_env *e)
{
	t_room	*r;
	t_path	*p;
	t_path	*tmp;

	r = e->end;
	p = create_p_node(e, r->name, 0);
	tmp = p;
	while (r->count != 2)
	{
		r = find_next_room(r->link, (r->count) - 1);
		tmp->next = create_p_node(e, r->name, 0);
		tmp = tmp->next;
	}
	r = find_next_room(r->link, (r->count) - 1);
	tmp->next = create_p_node(e, r->name, e->ant);
	tmp->next->next = NULL;
	return (p);
}
