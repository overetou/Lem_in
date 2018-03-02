/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:33:30 by kenguyen          #+#    #+#             */
/*   Updated: 2018/02/14 01:20:56 by kenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_pf_flag
{
	int			sp;
	int			plus;
	int			neg;
	int			minus;
	int			hash;
	int			zero;
	int			prec;
	int			width;
}				t_pf_flag;

typedef enum	e_pf_mod
{
	pf_nomod = 0,
	pf_h,
	pf_hh,
	pf_l,
	pf_ll,
	pf_j,
	pf_z,
}				t_pf_mod;

typedef	struct	s_pf_env
{
	va_list		ap;
	char		*out;
	t_pf_flag	flag;
	t_pf_mod	mod;
	int			i;
	int			ret;
}				t_pf_env;

/*
**				ft_printf
*/

int				ft_printf(const char *restrict fmt, ...);

/*
**				parse_arg
*/

void			init_flag(t_pf_flag *flag);
void			get_flag(const char *restrict fmt, t_pf_env *e);
void			get_prec(const char *restrict fmt, t_pf_env *e);
void			get_mod(const char *restrict fmt, t_pf_env *e);
void			get_spec(const char *restrict fmt, t_pf_env *e);

/*
**				get_spec
*/

void			spec_int(t_pf_env *e);
void			spec_unsint(t_pf_env *e, char type);
void			spec_char(t_pf_env *e, char type);
void			spec_wchar(t_pf_env *e, char type);
void			spec_base(t_pf_env *e, char type);
void			spec_ptraddr(t_pf_env *e, char type);
void			spec_percent(t_pf_env *e);

/*
**				print_digit
*/

void			print_digit(t_pf_env *e);
void			print_digit_width(t_pf_env *e);
void			print_digit_sign(t_pf_env *e);
void			check_digit_sign(t_pf_env *e);
void			check_digit_prec(t_pf_env *e);

/*
**				print_base
*/

void			print_base(t_pf_env *e, char type, long val);
void			print_base_width(t_pf_env *e, char type);
void			print_base_pre(t_pf_env *e, char type, long val);
void			check_base_prec(t_pf_env *e, char type);

/*
**				print_char
*/

void			print_char(t_pf_env *e, char c);
void			print_null_char(t_pf_env *e);
void			print_char_width(t_pf_env *e);
void			print_str(t_pf_env *e);
void			print_null_str(t_pf_env *e);
void			print_str_width(t_pf_env *e);

/*
**				print_wchar
*/

void			print_wchar(t_pf_env *e, wchar_t wc);
void			print_wchar_minus(t_pf_env *e, wchar_t wc);
void			print_wstr(t_pf_env *e, wchar_t *wc);
void			print_wstr_minus(t_pf_env *e, wchar_t *wc, int len);
int				get_wstr_len(wchar_t *wc);
void			put_wstr(t_pf_env *e, wchar_t c);
void			put_wstr_c(t_pf_env *e, char c);

/*
**				print_ptraddr
*/

void			print_ptraddr(t_pf_env *e, char type);
void			print_ptraddr_width(t_pf_env *e);
void			ptraddr_prec(t_pf_env *e);

/*
**				print_invalid
*/

void			print_invalid_spec(t_pf_env *e, char c);
void			print_invalid_width(t_pf_env *e);

#endif
