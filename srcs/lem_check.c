/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:56:59 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/12 19:02:01 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_room			*add_room(t_env *e, char *name)
{
	t_room *new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		lem_exit(e, NULL);
	if (!(new->name = ft_strdup(name)))
		lem_exit(e, NULL);
	new->link = NULL;
	new->next = NULL;
	new->count = 0;
	return (new);
}

t_room			*find_room(char *name, t_env *e)
{
	t_room *r;

	r = e->room;
	while (r)
	{
		if (ft_strcmp(name, r->name) == 0)
			return (r);
		r = r->next;
	}
	return (NULL);
}

void			print_path(t_path *p, t_env *e)
{
	if (e->color)
	{
		write(1, "\033[01;34m", 8);
		print_path_body(p);
		write(1, "\033[0m", 4);
	}
	else
		print_path_body(p);
	write(1, "\n\n", 2);
	del_path(p);
}

void			print_room(t_room *r)
{
	t_link	*tmp;

	while (r)
	{
		write(1, "----------\n", 11);
		ft_printf("Name = %s\n\n", r->name);
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
