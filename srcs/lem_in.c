/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:41:59 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/08 19:30:04 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void			lem_parse(t_env *e)
{
	char *line;

	store_ant(e);
	while (get_next_line(0, &line) > 0)
	{
		store_map(&e->map, line);
		if (!ft_strcmp(line, "##start"))
			store_start_end(e, "##start");
		else if (!ft_strcmp(line, "##end"))
			store_start_end(e, "##end");
		else if (line[0] == '#')
			store_map(&e->cmt, line);
		else if (ft_strchr(line, ' '))
			store_room(e, ft_strsplit(line, ' '));
		else if (ft_strchr(line, '-'))
		{
			e->line = ft_strdup(line);
			free(line);
			store_link(e);
			return ;
		}
		else
		{
			free(line);
			lem_exit(e, "Error on parsing");
		}
		free(line);
	}
}

void			lem_in(t_env *e)
{
	lem_parse(e);
	if (!e->start || !e->end)
		lem_exit(e, "no ##start or ##end");
	print_map(e->map);
	print_room(e->room);
}
