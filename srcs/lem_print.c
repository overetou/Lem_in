/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:21:49 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/09 14:18:50 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	print_map_color(t_data *map)
{
	while (map)
	{
		if ((map->name)[0] == '#')
		{
			if ((map->name)[1] == '#')
				write(1, "\033[01;34m", 8);
			else
				write(1, "\033[22;34m", 8);
			ft_printf("%s\n", map->name);
		}
		else
		{
			write(1, "\033[01;35m", 8);
			ft_printf("%s\n", map->name);
		}
		write(1, "\033[0m", 4);
		map = map->next;
	}
	ft_printf("\n");
}

void	print_map(t_data *map)
{
	while (map)
	{
		ft_printf("%s\n", map->name);
		map = map->next;
	}
	ft_printf("\n");
}

void	print_first(t_path *p, t_path *pth, t_env *e)
{
	if (e->color)
	{
		ft_printf("\033[01;35mL%d", p->a_name);
		if (p == pth)
			ft_printf("\033[22;32m-%s\033[0m", p->name);
		else
			ft_printf("\033[01;34m-%s\033[0m", p->name);
	}
	else
		ft_printf("L%d-%s", p->a_name, p->name);
}

void	print_ants(t_path *pth, t_env *e)
{
	t_path	*p;

	p = pth;
	while (p->next)
	{
		if (p->ant)
		{
			print_first(p, pth, e);
			p = p->next;
			break ;
		}
		p = p->next;
	}
	while (p->next)
	{
		if (p->ant)
		{
			if (e->color)
				ft_printf(" \033[01;35mL%d\033[01;34m-%s\033[0m", p->a_name, p->name);
			else
				ft_printf(" L%d-%s", p->a_name, p->name);
		}
		p = p->next;
	}
	ft_printf("\n");
}

//void			print_path(t_path *p)
//{
//	ft_putstr("Path : ");
//	while (p->next)
//	{
//		ft_printf("%s <- ", p->name);
//		p = p->next;
//	}
//	ft_putendl(p->name);
//}

void	print_room(t_room *r)
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
