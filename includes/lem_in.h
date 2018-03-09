/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:01:17 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/09 14:25:08 by kenguyen         ###   ########.fr       */
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

typedef	struct	s_path
{
	char			*name;
	int				a_name;
	int				ant;
	struct s_path	*next;
}				t_path;

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
	t_data		*cmt;
}				t_env;

/*
**				lem_in
*/

void			lem_in(t_env *e);
void			lem_parse(t_env *e);

/*
**				parse
*/

void			store_ant(t_env *e);
void			store_room(t_env *e, char **tab);
void			store_link(t_env *e, char **tab);
void			store_map(t_data **map, char *line);
void			store_start_end(t_env *e, char *str);
void			add_start_end(t_env *e, char **tab, char *str);

/*
**				check
*/

t_room			*add_room(char *name);
t_room			*find_room(char	*name, t_env *e);

/*
**				path
*/

int    	 		lem_path(t_env *e);
t_path			*get_path(t_env *e);
void			view_ants_moves(t_path *p, t_env *e);

/*
**				print
*/

void			print_map(t_data *map);
void			print_ants(t_path *p);

/*
**				exit
*/

void			lem_exit(t_env *e, char *msg);

//void			print_room(t_room *r);

#endif
