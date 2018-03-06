/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:41:39 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/06 14:48:32 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		lem_exit(t_env *e)
{
	if (e->start)
		free(e->start)
	if (e->end)
		free(e->end)
	ft_printf("ERROR\n")
	exit (0);
}
