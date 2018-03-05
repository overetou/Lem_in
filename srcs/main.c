/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:02:44 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/05 18:08:51 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	dsp_rooms(t_room *r)
{
	while (r)
	{
		ft_printf("Name = %s\n", r->name);
		ft_printf("start = %d\n", r->start);
		ft_printf("end = %d\n-----------------------------", r->end);
		r = r->next;
	}
}

int			main(void)
{
	t_env	e;
	t_room	*r;

	ft_bzero(&e, (sizeof(e)));
	r = parse(&e);
	dsp_rooms(r);
	return (0);
}
