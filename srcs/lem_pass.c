/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_pass.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:46:43 by overetou          #+#    #+#             */
/*   Updated: 2018/03/08 16:46:51 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void    dsp_ants(t_path *p)
{
    while (p->next)
    {
        if (p->ant)
        {
            ft_printf("L%d-%s", p->a_name, p->name);
            p = p->next;        
            break;
        }
        p = p->next;   
    }
    while (p->next)
    {
        if (p->ant)
            ft_printf(" L%d-%s", p->a_name, p->name);
        p = p->next;
    }
    write(1, "\n", 1);
}

void    mv_ants(t_path *p, t_env *e)
{
    t_path  *next;

    next = p->next;
    while (next->next)
    {
        if (next->ant)
        {
            p->a_name = next->a_name;
            p->ant += 1;
            next->ant = 0;
        }
        p = next;
        next = next->next;
    }
    if (next->ant)
    {
        (next->ant)--;
        p->a_name = e->ant - next->ant;
        p->ant += 1;
    }
}

void    view_ants_moves(t_path *p, t_env *e)
{
    t_path  *head;

    head = p;
    (void)e;
    while (p->ant != e->ant)
    {
        mv_ants(p, e);
        dsp_ants(p);
    }
}
