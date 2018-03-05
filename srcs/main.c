/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:02:44 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/05 15:50:55 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int			main(void)
{
	t_env	e;
	t_room	*r;

	r = malloc(sizeof(t_room));
	ft_bzero(&e, (sizeof(e)));
	parse(&e, r);
	ft_printf("e->ant = %d\n", e.ant);
	ft_printf("e->start = %d\n", e.start);
	ft_printf("e->end = %d\n", e.end);
	ft_printf("r->name = %s\n", r->name);
	return (0);
}
