/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:12:20 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/09 14:13:52 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	add_queue_link(t_room *r, t_link **last)
{
	(*last)->next = (t_link*)malloc(sizeof(t_link));
	(*last) = (*last)->next;
	(*last)->adress = r;
	(*last)->next = NULL;
}

int		process_connections(t_room *r, t_link **last, t_env *e)
{
	t_link  *tmp;

	tmp = r->link;
	while (tmp)
	{
		if (tmp->adress->count == 0)
		{
			tmp->adress->count = r->count + 1;
			if (tmp->adress == e->end)
				return (1);
			add_queue_link(tmp->adress, last);
		}
	tmp = tmp->next;
	}
	return (0);
}

int		lem_path(t_env *e)
{
	t_link  *queue;
	t_link  *tmp;
	t_link  *last;
	int x = 0;

	e->start->count = 1;
	queue = (t_link*)malloc(sizeof(t_link));
	queue->adress = e->start;
	tmp = queue;
	last = queue;
	while (tmp && x++ != 10)
	{
		printf("%s\n", tmp->adress->name);
		if (process_connections(tmp->adress, &last, e))
			return (1);
		tmp = tmp->next;
	}
	//del_queue(queue);
	return (0);
}
//----------------------------------------------------------------------------

t_room	*find_next_room(t_link *l, int count)
{
	while (l->adress->count != count)
		l = l->next;
	return (l->adress);
}

t_path	*create_p_node(char *name, int n)
{
	t_path	*new;

	new = (t_path*)malloc(sizeof(t_path));
	new->name = ft_strdup(name);
	new->ant = n;
	return (new);
}

t_path	*get_path(t_env *e)
{
	t_room	*r;
	t_path	*p;
	t_path	*tmp;

	r = e->end;
	p = create_p_node(r->name, 0);
    tmp = p;
	while (r->count != 2)
	{
		r = find_next_room(r->link, (r->count) - 1);
		tmp->next = create_p_node(r->name, 0);
		tmp = tmp->next;
	}
	r = find_next_room(r->link, (r->count) - 1);
	tmp->next = create_p_node(r->name, e->ant);
    tmp->next->next = NULL;
	return (p);
}
