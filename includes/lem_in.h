/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:01:17 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/12 19:29:03 by kenguyen         ###   ########.fr       */
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
	char			*n;
	int				an;
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
	int			color;
	int			path;
	int			error;
	int			comment;
}				t_env;

/*
**				lem_in
*/

void			print_help(t_env *e);
void			lem_parse(t_env *e);
void			lem_in(t_env *e);
void			get_arg(int argc, char **argv, t_env *e);

/*
**				store
*/

void			store_ant(t_env *e);
void			store_room(t_env *e, char **tab);
void			store_map(t_env *e, t_data **map, char *line);
void			store_start_end(t_env *e, char *str);
void			add_start_end(t_env *e, char **tab, char *str);

/*
**				check
*/

t_room			*add_room(t_env *e, char *name);
t_room			*find_room(char	*name, t_env *e);
void			print_path(t_path *p, t_env *e);
void			print_room(t_room *r);

/*
**				link
*/

int				check_link(t_env *e, char **tab);
void			create_link(t_env *e, t_room *room, t_room *adress);
void			add_link(t_env *e, char **tab);
void			store_link(t_env *e, char *line);

/*
**				pass
*/

int				lem_path(t_env *e);
void			mv_ants(t_path *p, t_env *e);
void			view_ants_moves(t_path *p, t_env *e);

/*
**				path
*/

void			add_queue_link(t_env *e, t_room *r, t_link **last);
int				process_connections(t_room *r, t_link **last, t_env *e);
t_room			*find_next_room(t_link *l, int count);
t_path			*create_p_node(t_env *e, char *name, int n);
t_path			*get_path(t_env *e);

/*
**				print
*/

void			print_map_color(t_data *map);
void			print_map(t_data *map);
void			print_first(t_path *p, t_path *pth, t_env *e);
void			print_ants(t_path *p, t_env *e);
void			print_path_body(t_path *p);

/*
**				exit
*/

void			lem_exit(t_env *e, char *msg);
void			del_room(t_room *r);
void			del_link(t_link *queue);
void			del_path(t_path *p);
void			destroy_data(t_data *data);

#endif
