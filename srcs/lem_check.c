/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:56:59 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/09 14:16:18 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_room			*add_room(char *name)
{
	t_room *new;

	new = (t_room*)malloc(sizeof(t_room));
	new->name = ft_strdup(name);
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
