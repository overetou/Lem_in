/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:35:00 by kenguyen          #+#    #+#             */
/*   Updated: 2018/02/11 14:44:32 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict fmt, ...)
{
	t_pf_env	e;

	ft_bzero(&e, sizeof(e));
	va_start(e.ap, fmt);
	while (fmt[e.i])
	{
		if (fmt[e.i] == '%' && fmt[e.i + 1] != '%')
		{
			++e.i;
			get_flag(fmt, &e);
			get_spec(fmt, &e);
		}
		else if (fmt[e.i] == '%' && fmt[e.i + 1] == '%')
		{
			e.ret += write(1, "%", 1);
			e.i += 2;
		}
		else
			e.ret += write(1, &fmt[e.i++], 1);
	}
	va_end(e.ap);
	return (e.ret);
}
