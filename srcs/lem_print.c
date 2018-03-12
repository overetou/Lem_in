/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:21:49 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/12 19:16:59 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		print_map_color(t_data *map)
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

void		print_map(t_data *map)
{
	while (map)
	{
		ft_printf("%s\n", map->name);
		map = map->next;
	}
	ft_printf("\n");
}

void		print_first(t_path *p, t_path *pth, t_env *e)
{
	if (e->color)
	{
		ft_printf("\033[01;35mL%d", p->an);
		if (p == pth)
			ft_printf("\033[22;32m-%s\033[0m", p->n);
		else
			ft_printf("\033[01;34m-%s\033[0m", p->n);
	}
	else
		ft_printf("L%d-%s", p->an, p->n);
}

void		print_ants(t_path *pth, t_env *e)
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
				ft_printf(" \033[01;35mL%d\033[01;34m-%s\033[0m", p->an, p->n);
			else
				ft_printf(" L%d-%s", p->an, p->n);
		}
		p = p->next;
	}
	ft_printf("\n");
}

void		print_path_body(t_path *p)
{
	if (p->next)
	{
		print_path_body(p->next);
		ft_printf(" -> ");
	}
	ft_putstr(p->n);
}
