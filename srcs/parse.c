/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:38:35 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/05 15:18:57 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

char		**check_line(char *line)
{
	char	**tab;
	char	*ret;
	int		i;

	i = 0;
	if (strcmp(line, "##start") == 0 || strcmp(line, "##end") == 0)
		return (line);
	tab = ft_strsplit(line, ' ');
	while (tab[i])
		i++;
	if (tab[0][0] == 'L' || tab[0][0] == '#' || i != 3)
		return (NULL);
	ret = ft_strdup(tab[0]);
	ft_strplitdel(tab);
	return (1);
}

void		parse(void)
{
	int		ant;
	char	*line;
	t_room	*r;

	ant = ft_atoi(line);
	r = (t_room*)malloc(sizeof(t_room));
	get_next_line(0, &line);
	free(line);
	if (ant == 0)
		return (0);	
	while (get_next_line(0, &line))
	{
		if (check_line(line))

		else
			break ;
	}
	return (0);
}
