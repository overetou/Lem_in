/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:41:59 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/06 17:23:56 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int store_mdr(t_env *e)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "##start") || ft_strcmp(line, "##end"))
			start_end(e, line);
	//	else if (line[0] == '#')
	//		store_cmt(e, line);
	//	else if (check_room(line))
	//		add_room(line);
	//	else if (check_link(e, line))
	//		return (1);
//		else
//		{
//			free(line);
//			lem_exit(e);
//			return (0);
//		}
		free(line);
	}
	return (0);
}

void		lem_parse(t_env *e)
{
	store_ant(e);
	store_mdr(e);
}

void		lem_in(t_env *e)
{
	lem_parse(e);
}
