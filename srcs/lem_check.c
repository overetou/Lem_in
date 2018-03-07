/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:56:59 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/07 19:57:01 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_room    *add_room(char *name)
{
    t_room *new;
    
    new = (t_room*)malloc(sizeof(t_room));
    new->name = ft_strdup(name);
    new->link = NULL;
    new->next = NULL;
    new->count = 0;
    return (new);
}

int        check_room(char *line)
{
    char    **tab;
    int        i;
    
    i = 0;
    tab = ft_strsplit(line, ' ');
    while (tab[i])
        i++;
    if (tab[0][0] == 'L' || tab[0][0] == '#' || i != 3
        || !ft_str_is_numeric(tab[1]) || !ft_str_is_numeric(tab[2]))
        return (0);
    ft_strsplitdel(tab);
    return (1);
}

t_room			*find_room(char	*name, t_env *e)
{
	t_room *r;

	r = e->room;
	while (r)
	{
		if (ft_strcmp(name, r->name) == 0)
			return (r);
		r = r->next;
	}
	return (NULL);
}

int			check_link(t_env *e, char *line)
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
