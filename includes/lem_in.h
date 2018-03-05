/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:01:17 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/05 17:21:47 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>

typedef struct	s_link
{
	char			*name;
	struct s_link	*next;
}				t_link;

typedef struct	s_room
{
	char			*name;
	struct t_link	*link;
	struct s_room	*next;
	int				start;
	int				end;
}				t_room;

typedef struct		s_env
{
	int		ant;
	int		start;
	int		end;
}					t_env;

t_room	*parse(t_env *e);

#endif
