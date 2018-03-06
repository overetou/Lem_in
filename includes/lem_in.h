/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:01:17 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/06 14:57:05 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>

typedef struct	s_room
{
	char			*name;
	struct t_link	*link;
	struct s_room	*next;
	int				start;
	int				end;
}				t_room;

typedef struct	s_link
{
	char			*name;
	struct s_link	*next;
}				t_link;

typedef struct	s_cmt
{
	char			*cmt;
	struct s_link	*next;
}				t_cmt;

typedef struct		s_env
{
	t_room	*room;
	t_link	*link;
	t_cmt	*cmt;
	int		ant;
	char	*start;
	char	*end;
}					t_env;

void		lem_in(t_env *e);
void		store_ant(t_env *e);
void		store_start(t_env *e);
void		store_end(t_env *e);
void		store_cmt(t_env *e);
void		store_room(t_env *e);
void		store_link(t_env *e);
void		lem_exit(t_env *e);

#endif
