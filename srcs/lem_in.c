/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:41:59 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/09 14:17:43 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void			print_help(t_env *e)
{
	ft_printf("\nA correct map contains 3 parts, in ");
	ft_printf("the given order :\n\t[ant number]\n\t[rooms]\n\t[links]\n\n");
	ft_printf("Room field pattern :\n\t\"name coord(x) coord(y)\"\ntube field");
	ft_printf(" pattern :\n\tname(1)-name(2)\nThe starting point must be ");
	ft_printf("preceded by ##start and the ending point by ##end.\n\n");
	ft_printf("Example :\n5\n##start\nstart 0 0\nmidway 0 1\n##end\n");
	ft_printf("end 0 2\nstart-midway\nmidway-end\n\nlines preceded by");
	ft_printf(" a single # may be placed anywhere in the map.\n");
	lem_exit(e, NULL);
}

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
			e->line = line;
			store_link(e);
			break;
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
	if (!(e->start->link) || !lem_path(e))
		lem_exit(e, "no path");
	(e->color) ? print_map_color(e->map) : print_map(e->map);
	destroy_data(e->map);
	if (e->path)
		print_path(get_path(e), e);
	else
		view_ants_moves(get_path(e), e);
	del_room(e->room);
	destroy_data(e->cmt);
}

void			get_arg(int argc, char **argv, t_env *e)
{
	int i;

	if (argc != 1)
	{
		i = 1;
		while (i != argc)
		{
			if (ft_strcmp(argv[i], "-color") == 0)
				e->color = 1;
			else if (ft_strcmp(argv[i], "-h") == 0)
				print_help(e);
			else if (ft_strcmp(argv[i], "-path") == 0)
				e->path = 1;
			else
				lem_exit(e, "Invalid argument(s).");
			i++;
		}
	}
}

int				main(int argc, char **argv)
{
	t_env	e;

	ft_bzero(&e, (sizeof(e)));
	get_arg(argc, argv, &e);
	lem_in(&e);
	return (0);
}
