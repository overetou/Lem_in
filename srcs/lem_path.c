/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:43:56 by overetou          #+#    #+#             */
/*   Updated: 2018/03/07 19:44:21 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	add_queue_link(t_room *r, t_link **last)
{
    (*last)->next = (t_link*)malloc(sizeof(t_link));
    (*last) = (*last)->next;
    (*last)->adress =r;
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

    e->start->count = 1;
    queue = (t_link*)malloc(sizeof(t_link));
    queue->adress = e->start;
    tmp = queue;
    last = queue;
    while(tmp)
    {
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
	tmp = create_p_node(r->name, 0);
	tmp->next = NULL;
	while (r->count != 2)
	{
		r = find_next_room(r->link, (r->count) - 1);
		p = create_p_node(r->name, 0);
		p->next = tmp;
		tmp = p;
	}
	r = find_next_room(r->link, (r->count) - 1);
	p = create_p_node(r->name, e->ant);
	p->next = tmp;
	return (p);
}
