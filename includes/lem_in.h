/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:01:17 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/08 15:17:16 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>

typedef struct	s_data
{
	char			*name;
	struct s_data	*next;
}				t_data;

typedef struct	s_link
{
	struct s_room	*adress;
	struct s_link	*next;
}				t_link;

typedef struct	s_room
{
	char			*name;
	t_link			*link;
	int				count;
	struct s_room	*next;
}				t_room;

typedef struct	s_env
{
	int			ant;
	t_room		*room;
	t_room		*start;
	t_room		*end;
	t_data		*map;
	char		*line;
}				t_env;

/*
**				lem_in
*/

void			lem_in(t_env *e);

/*
**				parse
*/

void			lem_parse(t_env *e);
void			store_ant(t_env *e);
void			store_startend(t_env *e, char *line);
void			store_room(t_env *e, char *line);
int				store_link(t_env *e);
void			store_map(t_data **map, char *line);

/*
**				check
*/

int				check_room(char *line);
int				check_link(t_env *e, char *line);
t_room			*add_room(char *name);
t_room			*find_room(char	*name, t_env *e);

/*
**				print
*/

void			print_room(t_room *r);

/*
**				exit
*/

void			lem_exit(t_env *e);

#endif
