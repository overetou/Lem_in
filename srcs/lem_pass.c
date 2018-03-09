/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_pass.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:12:30 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/09 14:16:38 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		mv_ants(t_path *p, t_env *e)
{
	t_path	*next;

	next = p->next;
	while (next->next)
	{
		if (next->ant)
		{
			p->a_name = next->a_name;
			p->ant += 1;
			next->ant = 0;
		}
		p = next;
		next = next->next;
	}
	if (next->ant)
	{
		(next->ant)--;
		p->a_name = e->ant - next->ant;
		p->ant += 1;
	}
}

void		view_ants_moves(t_path *p, t_env *e)
{
	t_path	*head;

	head = p;
	while (p->ant != e->ant)
	{
		mv_ants(p, e);
		print_ants(p, e);
	}
}
