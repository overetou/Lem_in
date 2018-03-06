/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:38:35 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/06 15:56:43 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	dsp_rooms(t_room *r)
{
	while (r)
	{
		ft_printf("Name = %s\n", r->name);
		ft_printf("start = %d\n", r->start);
		ft_printf("end = %d\n-----------------------------\n", r->end);
		r = r->next;
	}
}

t_room	*add_room(char *name)
{
	t_room *new;
	
	new = (t_room*)malloc(sizeof(t_room));
	new->start = 0;
	new->end = 0;
	new->name = name;
	new->next = NULL;
	return (new);
}

int		check_room(char *line)
{
	char	**tab;
	int		i;
	
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

int		start_end(t_env *e, char *str, char **line, t_room *r)
{
	if (ft_strcmp(str, "start") == 0 && !e->start)
	{
		(e->start)++;
		r->start = 1;
	}
	else if (ft_strcmp(str, "end") == 0 && !e->end)
	{
		(e->end)++;
		r->end = 1;
	}
	else 
		return (0);
	//free(line);
	get_next_line(0, line);
	return (1);
}

t_room	*parse(t_env *e)
{
	char	*line;
	t_room	*r;
	t_room	*head;

	get_next_line(0, &line);
	e->ant = ft_atoi(line);
	free(line);
	r = add_room();
	head = r;
	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "##", 2) == 0)
			start_end(e, line + 2, &line, head);
		if (!check_line(line, head))
			break ;
		head->next = add_room();
		head = head->next;
		//else if (check_tube(line))
		//	return ;
		free(line);
	}
	head = r;
	while ((head->next)->next)
		head = head->next;
	head->next = NULL;
	dsp_rooms(r);
	return (r);
}
