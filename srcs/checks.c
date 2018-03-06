/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:03:50 by overetou          #+#    #+#             */
/*   Updated: 2018/03/06 16:17:53 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	find_room(char	*name, t_env *env)
{
	t_room *r;

	r = e->room;
	while (r)
	{
		if (ft_strcmp(name, r->name) == 0)
			return (1);
		r = r->next;
	}
	return (0);
}

int	check_link(char *line)
{
	char	**tab;
	int		x;

	tab = ft_strsplit(line, '-');
	x = 0;
	while (tab[x])
		x++;
	if (x == 2 && find_room(tab[0], e) && find_room(tab[1], e))
		return (1);
	return (0);
}
