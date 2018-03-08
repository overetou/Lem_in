/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:21:49 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/08 21:27:05 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void			print_map(t_data *map)
{
	while (map)
	{
		ft_printf("%s\n", map->name);
		map = map->next;
	}
	ft_printf("\n");
}

void			print_ants(t_path *p)
{
	while (p->next)
	{
		if (p->ant)
		{
			ft_printf("L%d-%s", p->a_name, p->name);
			p = p->next;
			break;
		}
		p = p->next;
	}
	while (p->next)
	{
		if (p->ant)
			ft_printf(" L%d-%s", p->a_name, p->name);
		p = p->next;
	}
	ft_printf("\n");
}

/*
void			dsp_path(t_path *p)
{
	ft_putstr("Path : ");
	while (p->next)
	{
		ft_printf ("%s <- ", p->name);
		p = p->next;
	}
	ft_putendl(p->name);
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
*/
