/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:41:39 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/12 19:27:05 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		del_path(t_path *p)
{
	t_path *next;

	while (p)
	{
		next = p->next;
		free(p->n);
		free(p);
		p = next;
	}
}

void		del_room(t_room *r)
{
	t_room *next;

	while (r)
	{
		next = r->next;
		del_link(r->link);
		free((r->name));
		free(r);
		r = next;
	}
}

void		del_link(t_link *queue)
{
	t_link *next;

	while (queue)
	{
		next = queue->next;
		free(queue);
		queue = next;
	}
}

void		destroy_data(t_data *data)
{
	if (data)
	{
		if (data->name)
			free(data->name);
		destroy_data(data->next);
		free(data);
	}
}

void		lem_exit(t_env *e, char *msg)
{
	if (e->error)
		print_map(e->map);
	if (e->map)
		destroy_data(e->map);
	if (e->cmt)
		destroy_data(e->cmt);
	if (e->room)
		del_room(e->room);
	if (msg)
		ft_printf("%s\n", msg);
	exit(0);
}
