/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:38:35 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/05 16:28:14 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		ft_exit()
{
	ft_printf("ERROR\n");
	exit(0);
}

void		start_end(t_env *e, t_room *r)
{
	char **tab;
	char *line;
	int i;

	i = 0;
	get_next_line(0, &line);
	tab = ft_strsplit(line, ' ');
	while (tab[++i])
		;
	if (tab[0][0] == 'L' || tab[0][0] == '#' || i != 3)
		return (ft_exit()) ;
	r->name = ft_strdup(tab[0]);
	ft_strsplitdel(tab);
	free(line);
	e->start = 1;
}

t_room		*parse(t_env *e)
{
	char	*line;
	t_room	*r;

	get_next_line(0, &line);
	e->ant = ft_atoi(line);
	while (1)
	{
		r = (t_room*)malloc(sizeof(t_room));
		if (get_next_line(0, &line) < 1)
			break ;
		if (!ft_strncmp(line, "##"))
			start_end(e, r, line + 2));
		if (check_line(new_line))
			r = r->next;
		else if (check_tube(line))
			return ;
		free(line);
	}
}
