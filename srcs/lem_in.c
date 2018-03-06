/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:41:59 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/06 16:18:52 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		lem_parse(t_env *e)
{
	char *line;

	store_ant(e);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "##start") || ft_strcmp(line, "##end"))
			start_end(e, line);
		else if (line[0] == '#')
			store_cmt(e, line);
		else if (check_room(line))
			add_room(line);
		else
		{
			free(line);
			lem_exit(e);
		}
		free(line);
	}
}

void		lem_in(t_env *e)
{
	lem_parse(e);
}
