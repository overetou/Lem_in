/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:01:17 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/07 14:24:04 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>

typedef struct	s_data
{
	char			*name;
	struct s_data 	*next;
}				t_data;

typedef struct	s_room
{
	char			*name;
	t_data			*link;
	struct s_room	*next;
}				t_room;

typedef struct		s_env
{
	t_room	*room;
	t_data	*link;
	t_data	*cmt;
	int		ant;
	t_room	*start;
	t_room	*end;
}					t_env;

void		lem_in(t_env *e);
void		store_ant(t_env *e);
void		start_end(t_env *e, char *line);
void		store_cmt(t_env *e, char *line);
void		store_room(t_env *e, char *line);
int			store_link(t_env *e);
void		lem_exit(t_env *e);
t_room		*add_room(char *name);
int			check_room(char *line);
t_data		*create_link(t_room *room, char *name);
int			check_link(t_env *e, char *line);
int			store_mdr(t_env *e);
void		dsp_rooms(t_room *r);

#endif
