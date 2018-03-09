/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:41:39 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/09 13:39:13 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		destroy_data(t_data *data)
{
	if (data)
	{
		if (data->name)
			free(data->name);
		destroy_data(data->next);
		free(data);
	}
}

void		lem_exit(t_env *e, char *msg)
{
	print_map(e->map);
	if (e->map)
		destroy_data(e->map);
	if (e->cmt)
		destroy_data(e->cmt);
	if (msg)
		ft_printf("%s\n", msg);
	exit(0);
}
