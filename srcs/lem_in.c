/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:41:59 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/06 14:57:15 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		lem_parse(t_env *e)
{
	char *line;

	store_ant(e);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "##start"))
			store_start(e);
		else if (ft_strcmp(line, "##end"))
			store_end(e);
		else if (line[0] == '#')
			store_cmt(e);
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
